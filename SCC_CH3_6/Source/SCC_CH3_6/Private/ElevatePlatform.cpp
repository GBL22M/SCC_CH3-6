#include "ElevatePlatform.h"
#include "Components/BoxComponent.h"
#include "PlayerCharacter.h"

AElevatePlatform::AElevatePlatform()
	:MoveSpeed(40.f)
	,MaxDistance(200.f)
	,CanElevate(false)
	,StartPositionZ(0.f)
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Fantastic_Village_Pack/meshes/props/deco/SM_PROP_firepit.SM_PROP_firepit"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	StaticMesh->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.f));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootComponent);
	BoxCollision->SetGenerateOverlapEvents(true);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AElevatePlatform::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AElevatePlatform::OnOverlapEnd);

}

void AElevatePlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartPositionZ = GetActorLocation().Z;
}

void AElevatePlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	if (PlayerCharacter)
	{
		CanElevate = true;
	}
}

void AElevatePlatform::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	if (PlayerCharacter)
	{
		CanElevate = false;
	}
}

void AElevatePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanElevate)
	{
		Elevate(DeltaTime);
	}
	if (!CanElevate)
	{
		Descened(DeltaTime);
	}
}

void AElevatePlatform::Elevate(float DeltaTime)
{
	if (GetActorLocation().Z < MaxDistance)
	{
		AddActorLocalOffset(FVector(0.f, 0.f, MoveSpeed * DeltaTime));
	}
}

void AElevatePlatform::Descened(float DeltaTime)
{
	if(GetActorLocation().Z > StartPositionZ)	
	{
		AddActorLocalOffset(FVector(0.f, 0.f, -MoveSpeed * DeltaTime));
	}
}