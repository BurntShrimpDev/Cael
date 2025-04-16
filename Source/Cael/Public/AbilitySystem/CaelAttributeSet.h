// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CaelAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class CAEL_API UCaelAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UCaelAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// === VITAL ===
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes|Vital")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Energy, Category = "Attributes|Vital")
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Energy)


	// === PRIMARY ===
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Might, Category = "Attributes|Primary")
	FGameplayAttributeData Might;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Might)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Precision, Category = "Attributes|Primary")
	FGameplayAttributeData Precision;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Precision)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resolve, Category = "Attributes|Primary")
	FGameplayAttributeData Resolve;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Resolve)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Focus, Category = "Attributes|Primary")
	FGameplayAttributeData Focus;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Focus)


	// === SECONDARY ===
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes|Secondary")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxEnergy, Category = "Attributes|Secondary")
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, MaxEnergy)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagazineSize, Category = "Attributes|Secondary")
	FGameplayAttributeData MagazineSize;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, MagazineSize)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CritChance, Category = "Attributes|Secondary")
	FGameplayAttributeData CritChance;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, CritChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaggerDamage, Category = "Attributes|Secondary")
	FGameplayAttributeData StaggerDamage;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, StaggerDamage)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AbilityPower, Category = "Attributes|Secondary")
	FGameplayAttributeData AbilityPower;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, AbilityPower)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AoERadius, Category = "Attributes|Secondary")
	FGameplayAttributeData AoERadius;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, AoERadius)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CooldownReduction, Category = "Attributes|Secondary")
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, CooldownReduction)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FireRate, Category = "Attributes|Secondary")
	FGameplayAttributeData FireRate;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, FireRate)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WeakSpotBonus, Category = "Attributes|Secondary")
	FGameplayAttributeData WeakSpotBonus;
	ATTRIBUTE_ACCESSORS(UCaelAttributeSet, WeakSpotBonus)

	// === PRIMARY ===
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Might)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Precision)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Resolve)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, Focus)

	// === SECONDARY ===
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, MaxHealth)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, MaxEnergy)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, MagazineSize)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, CritChance)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, StaggerDamage)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, AbilityPower)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, AoERadius)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, CooldownReduction)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, FireRate)
	//ATTRIBUTE_ACCESSORS(UCaelAttributeSet, WeakSpotBonus)

	// === OnRep functions ===

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData& OldEnergy) const;

	UFUNCTION()
	void OnRep_Might(const FGameplayAttributeData& OldMight) const;

	UFUNCTION()
	void OnRep_Precision(const FGameplayAttributeData& OldPrecision) const;

	UFUNCTION()
	void OnRep_Resolve(const FGameplayAttributeData& OldResolve) const;

	UFUNCTION()
	void OnRep_Focus(const FGameplayAttributeData& OldFocus) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy) const;

	UFUNCTION()
	void OnRep_MagazineSize(const FGameplayAttributeData& OldMagazineSize) const;

	UFUNCTION()
	void OnRep_CritChance(const FGameplayAttributeData& OldCritChance) const;

	UFUNCTION()
	void OnRep_StaggerDamage(const FGameplayAttributeData& OldStaggerDamage) const;

	UFUNCTION()
	void OnRep_AbilityPower(const FGameplayAttributeData& OldAbilityPower) const;

	UFUNCTION()
	void OnRep_AoERadius(const FGameplayAttributeData& OldAoERadius) const;

	UFUNCTION()
	void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction) const;

	UFUNCTION()
	void OnRep_FireRate(const FGameplayAttributeData& OldFireRate) const;

	UFUNCTION()
	void OnRep_WeakSpotBonus(const FGameplayAttributeData& OldWeakSpotBonus) const;


	static FGameplayAttribute GetAttributeFromTag(const FGameplayTag& Tag);
};
