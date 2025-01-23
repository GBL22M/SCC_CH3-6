#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class SCC_CH3_6_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Setting Values")
	FRotator Rotator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Setting Values")
	float YawValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Setting Values")
	float PitchValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Setting Values")
	float RollValue;
};
