#include "RotatingPlatform.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ARotatingPlatform::ARotatingPlatform()
	:Rotator(FRotator(0.f, 0.f, 0.f))	
	,YawValue(0.f)
	,PitchValue(0.f)
	,RollValue(0.f)
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fantastic_Village_Pack/meshes/props/construction/SM_PROP_foundation_wood_03.SM_PROP_foundation_wood_03"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	Rotator = FRotator(YawValue, PitchValue, RollValue);
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(YawValue) || !FMath::IsNearlyZero(PitchValue)|| !FMath::IsNearlyZero(RollValue))
	{
		AddActorLocalRotation(Rotator);
	}
}