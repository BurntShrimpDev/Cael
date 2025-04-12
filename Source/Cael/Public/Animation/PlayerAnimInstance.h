// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CAEL_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	// Cached Player Pawn
	UPROPERTY(Transient, BlueprintReadOnly, Category="Character")
	TWeakObjectPtr<APawn> CachedPawn;

	/** Locomotion State */

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float Direction;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsInAir;

	// GAS (For Future Use)
	//UPROPERTY(BlueprintReadOnly, Category="GAS")
	//TObjectPtr<UAbilitySystemComponent> ASC;

	
};
