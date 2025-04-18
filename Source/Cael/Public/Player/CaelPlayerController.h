// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CaelPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class CAEL_API ACaelPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ACaelPlayerController();

protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:

	// Input Mapping Contexts
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> GameplayContext;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	int32 GameplayContextPriority = 0;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> MenuContext;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	int32 MenuContextPriority = 1;

	// Input Actions
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> AimAction;

	void Move(const FInputActionValue& InputActionValue);

	void Look(const FInputActionValue& InputActionValue);

	void StartAim(const FInputActionValue& InputActionValue);

	void StopAim(const FInputActionValue& InputActionValue);
};



