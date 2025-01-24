#include "PlatformSpawner.h"
#include "Engine/DataTable.h"
#include "PlatformSpawnData.h"
#include "FallingPlatform.h"

APlatformSpawner::APlatformSpawner()
	:SpawnDataTable(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
}

void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPlatform();
}


void APlatformSpawner::SpawnPlatform()
{
	if (!SpawnDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn Fail"));
		return;
	}

	TArray<FName> RowNames = SpawnDataTable->GetRowNames();
	for (const FName RowName : RowNames)
	{
		FPlatformSpawnData* Row = SpawnDataTable->FindRow<FPlatformSpawnData>(RowName, "");
		if (Row)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;

			GetWorld()->SpawnActor<AFallingPlatform>(
				AFallingPlatform::StaticClass()
				, Row->Position
				, Row->Rotator
				, SpawnParams
			);
			UE_LOG(LogTemp, Warning, TEXT("Spawned Platform: %s"), *Row->Position.ToString());
		}
	}
}