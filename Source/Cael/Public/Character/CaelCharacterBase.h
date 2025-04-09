// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CaelCharacterBase.generated.h"

UCLASS()
class CAEL_API ACaelCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACaelCharacterBase();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
