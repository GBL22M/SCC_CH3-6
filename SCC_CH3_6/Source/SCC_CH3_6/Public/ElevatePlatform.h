#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElevatePlatform.generated.h"

class UBoxComponent;

UCLASS()
class SCC_CH3_6_API AElevatePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AElevatePlatform();

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:	
	virtual void Tick(float DeltaTime) override;
	void Elevate(float DeltaTime);
	void Descened(float DeltaTime);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UBoxComponent* BoxCollision;

private:
	float MoveSpeed;
	float MaxDistance;
	bool CanElevate;
	double StartPositionZ;
};
