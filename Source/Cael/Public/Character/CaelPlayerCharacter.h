// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "Character/CaelCharacterBase.h"
#include "CaelPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class CAEL_API ACaelPlayerCharacter : public ACaelCharacterBase
{
	GENERATED_BODY()

	public:
	ACaelPlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float DefaultFOV = 95.f;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float AimingFOV = 70.f;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float DefaultArmLength = 450.f;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float AimingArmLength = 250.f;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float ZoomInterpSpeed = 10.f;

private:
	bool bIsAiming = false;

	void InitAbilityActorInfo();
	
};
