// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "Character/CaelCharacterBase.h"
#include "CaelEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CAEL_API ACaelEnemyCharacter : public ACaelCharacterBase
{
	GENERATED_BODY()

public:
	ACaelEnemyCharacter();

protected:
	virtual void BeginPlay() override;
};
