// Copyright Burnt Shrimp


#include "Player/CaelPlayerState.h"

#include "AbilitySystem/CaelAbilitySystemComponent.h"
#include "AbilitySystem/CaelAttributeSet.h"

ACaelPlayerState::ACaelPlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UCaelAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UCaelAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACaelPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
