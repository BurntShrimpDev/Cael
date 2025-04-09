// Copyright Burnt Shrimp


#include "Character/CaelCharacterBase.h"


ACaelCharacterBase::ACaelCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void ACaelCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACaelCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACaelCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

