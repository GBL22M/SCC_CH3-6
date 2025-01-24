#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

class AFallingPlatform;
class UDataTable;

UCLASS()
class SCC_CH3_6_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformSpawner();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void SpawnPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformSpawn")
	UDataTable* SpawnDataTable;
};
