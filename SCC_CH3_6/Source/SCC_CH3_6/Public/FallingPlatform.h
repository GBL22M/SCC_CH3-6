#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FallingPlatform.generated.h"

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
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;

private:
	FTimerHandle TimerHandle;
};
