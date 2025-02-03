#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingPlatform.generated.h"

class UBoxComponent;

UCLASS()
class SCC_CH3_6_API AFallingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AFallingPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void Falling();
	UFUNCTION()
	void Reset();

	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Settings")
	double MinDelayTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Settings")
	double MaxDelayTime;

private: 
	FTimerHandle TimerHandle;
	FTimerHandle ResetTimerHandle;

	FVector OriginLocation;

	double DelayTime;
	double ResetTime;

	bool BeforeOverlapped;
	bool Simulated;
};
