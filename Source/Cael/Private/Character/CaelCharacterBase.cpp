// Copyright Burnt Shrimp


#include "Character/CaelCharacterBase.h"


ACaelCharacterBase::ACaelCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* ACaelCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void ACaelCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}




