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
		}
	}
}

