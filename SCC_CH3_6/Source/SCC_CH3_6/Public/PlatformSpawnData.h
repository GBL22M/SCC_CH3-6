// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformSpawnData.generated.h"

USTRUCT(BlueprintType)
struct SCC_CH3_6_API FPlatformSpawnData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector Position;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FRotator Rotator;
};
