// Copyright Burn Shrimp

#pragma once

// GAS boilerplate accessors
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

// Meta-tagged attribute declaration + accessor block
#define ATTRIBUTE_WITH_TAG_ACCESSORS(ClassName, PropertyName, CategoryName, TagString) \
UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_##PropertyName, Category = CategoryName, meta = (GameplayTag = TagString)) \
FGameplayAttributeData PropertyName; \
ATTRIBUTE_ACCESSORS(ClassName, PropertyName)