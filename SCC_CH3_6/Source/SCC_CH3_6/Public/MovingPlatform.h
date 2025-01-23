#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class SCC_CH3_6_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void MovePlatformToXAxis(float DeltaTime);

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Setting Values")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Setting Values")
	float MoveSpeed;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Setting Values")
	float MaxRange;
};
