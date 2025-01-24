#include "FallingPlatform.h"

AFallingPlatform::AFallingPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fantastic_Village_Pack/meshes/props/natural/SM_PROP_hay_06.SM_PROP_hay_06"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
}

void AFallingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFallingPlatform::Falling, 5.f, true);
}

void AFallingPlatform::Falling()
{
	//일정 시간 지나면 떨어진다.
	StaticMesh->SetSimulatePhysics(true);
}

void AFallingPlatform::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	//player 체크
}
