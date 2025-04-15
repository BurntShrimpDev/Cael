// Copyright Burnt Shrimp


#include "AbilitySystem/CaelAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UCaelAttributeSet::UCaelAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitEnergy(100.f);
	InitMaxEnergy(100.f);
}

void UCaelAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
#define DOREP(Attr) DOREPLIFETIME_CONDITION_NOTIFY(UCaelAttributeSet, Attr, COND_None, REPNOTIFY_Always)

	// Vital
	DOREP(Health)
	DOREP(Energy)

	// Primary
	DOREP(Might)
	DOREP(Precision)
	DOREP(Resolve)
	DOREP(Focus)

	// Secondary
	DOREP(MaxHealth)
	DOREP(MaxEnergy)
	DOREP(MagazineSize)
	DOREP(CritChance)
	DOREP(StaggerDamage)
	DOREP(AbilityPower)
	DOREP(AoERadius)
	DOREP(CooldownReduction)
	DOREP(FireRate)
	DOREP(WeakSpotBonus)

#undef DOREP
}

#define DEFINE_REP_FUNC(Attr) \
void UCaelAttributeSet::OnRep_##Attr(const FGameplayAttributeData& Old##Attr) const \
{ \
GAMEPLAYATTRIBUTE_REPNOTIFY(UCaelAttributeSet, Attr, Old##Attr); \
}

DEFINE_REP_FUNC(Health)
DEFINE_REP_FUNC(Energy)
DEFINE_REP_FUNC(MaxHealth)
DEFINE_REP_FUNC(MaxEnergy)
DEFINE_REP_FUNC(Might)
DEFINE_REP_FUNC(Precision)
DEFINE_REP_FUNC(Resolve)
DEFINE_REP_FUNC(Focus)
DEFINE_REP_FUNC(MagazineSize)
DEFINE_REP_FUNC(CritChance)
DEFINE_REP_FUNC(StaggerDamage)
DEFINE_REP_FUNC(AbilityPower)
DEFINE_REP_FUNC(AoERadius)
DEFINE_REP_FUNC(CooldownReduction)
DEFINE_REP_FUNC(FireRate)
DEFINE_REP_FUNC(WeakSpotBonus)

#undef DEFINE_REP_FUNC


FGameplayAttribute UCaelAttributeSet::GetAttributeFromTag(const FGameplayTag& Tag)
{
	for (TFieldIterator<const FProperty> It(StaticClass()); It; ++It)
	{
		FProperty* Property = const_cast<FProperty*>(*It);
		if (FStructProperty* StructProp = CastField<FStructProperty>(Property))
		{
			if (StructProp->Struct == TBaseStructure<FGameplayAttributeData>::Get())
			{
				FString MetaTag = Property->GetMetaData(TEXT("GameplayTag"));
				if (!MetaTag.IsEmpty() && FGameplayTag::RequestGameplayTag(FName(*MetaTag)) == Tag)
				{
					return FGameplayAttribute(Property); 
				}
			}
		}
	}
	return FGameplayAttribute();
}
