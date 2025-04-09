// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CaelCharacterBase.generated.h"

UCLASS(Abstract)
class CAEL_API ACaelCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACaelCharacterBase();

protected:
	
	virtual void BeginPlay() override;	

};
