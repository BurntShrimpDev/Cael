// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CaelEffectActor.generated.h"

class USphereComponent;

UCLASS()
class CAEL_API ACaelEffectActor : public AActor
{
	GENERATED_BODY()

public:
	ACaelEffectActor();

	UFUNCTION()
	virtual void OnOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyState,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
