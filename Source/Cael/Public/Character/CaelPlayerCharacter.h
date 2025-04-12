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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<UCameraComponent> FollowCamera;
	
};
