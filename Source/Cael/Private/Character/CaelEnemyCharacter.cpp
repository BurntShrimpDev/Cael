// Copyright Burnt Shrimp


#include "Character/CaelEnemyCharacter.h"

#include "AbilitySystem/CaelAbilitySystemComponent.h"
#include "AbilitySystem/CaelAttributeSet.h"

ACaelEnemyCharacter::ACaelEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UCaelAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UCaelAttributeSet>("AttributeSet");
}

void ACaelEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
