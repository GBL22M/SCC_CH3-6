#include "MovingPlatform.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
	:StartLocation(FVector::ZeroVector)
	,MoveSpeed(0.f)
	,MaxMoveSpeed(200.f)
	,MinMoveSpeed(-200.f)
	,MoveRange(0.f)
	,MaxMoveRange(250.f)
	,MinMoveRange(100.f)
	,RandomOffsetRange(100.f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMesh);	

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Fantastic_Village_Pack/meshes/props/construction/SM_PROP_bridge_wood_02.SM_PROP_bridge_wood_02"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
}	

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();	

	StartLocation = GetActorLocation();
	float YOffset = FMath::RandRange(-RandomOffsetRange, RandomOffsetRange);
	StartLocation.Y += YOffset;

	SetActorRelativeLocation(StartLocation);
	MoveRange = FMath::RandRange(MinMoveRange, MaxMoveRange);

	if (FMath::RandBool())
	{
		MoveSpeed = MinMoveSpeed;
	}
	else
	{
		MoveSpeed = MaxMoveSpeed;
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatformToXAxis(DeltaTime);	
}

void AMovingPlatform::MovePlatformToXAxis(float DeltaTime)
{
	FVector newLocation = GetActorLocation();

	if (FVector::Dist(newLocation, StartLocation) > MoveRange)
	{
		MoveSpeed *= -1;
	}
	AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.f, 0.f));
}
