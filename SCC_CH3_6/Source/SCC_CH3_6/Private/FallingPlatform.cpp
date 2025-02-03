#include "FallingPlatform.h"
#include "Components/BoxComponent.h"
#include "PlayerCharacter.h"

AFallingPlatform::AFallingPlatform()
	:MinDelayTime(5.f)
	,MaxDelayTime(7.f)
	,DelayTime(0.f)
	,ResetTime(3.f)
	,BeforeOverlapped(false)
	, Simulated(false)
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fantastic_Village_Pack/meshes/props/natural/SM_PROP_hay_06.SM_PROP_hay_06"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
			
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootComponent);
	
	//box collision 크기 조절
	BoxCollision->SetRelativeLocation(FVector(0.f, 0.f, 80.f));
	BoxCollision->SetBoxExtent(FVector(50.f, 50.f, 80.f));
	BoxCollision->SetGenerateOverlapEvents(true);

}

void AFallingPlatform::BeginPlay()
{
	Super::BeginPlay();

	DelayTime = FMath::RandRange(MinDelayTime, MaxDelayTime);
	OriginLocation = GetActorLocation();
}

void AFallingPlatform::Falling()
{
	//일정 시간 지나면 떨어진다.
	StaticMesh->SetSimulatePhysics(true);
	Simulated = true;

	//떨어져있고,
	if (Simulated)
	{
		//일정 시간 지난 후 Reset 실행
		GetWorld()->GetTimerManager().SetTimer(ResetTimerHandle, this, &AFallingPlatform::Reset, ResetTime, true);
	}
}

void AFallingPlatform::Reset()
{
	SetActorLocation(OriginLocation);
	BeforeOverlapped = false;
	StaticMesh->SetSimulatePhysics(false);

	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(ResetTimerHandle);
}

void AFallingPlatform::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	//player 체크
	if (!BeforeOverlapped)
	{
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
		if (PlayerCharacter)
		{			
			BeforeOverlapped = true;		
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFallingPlatform::Falling, DelayTime, true);		
		}
	}
}
