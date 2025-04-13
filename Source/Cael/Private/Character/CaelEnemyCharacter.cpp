// Copyright Burnt Shrimp


#include "Character/CaelEnemyCharacter.h"

#include "AbilitySystem/CaelAbilitySystemComponent.h"
#include "AbilitySystem/CaelAttributeSet.h"

ACaelEnemyCharacter::ACaelEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCaelAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UCaelAttributeSet>("AttributeSet");
}
