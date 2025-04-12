// Copyright Burnt Shrimp


#include "Animation/PlayerAnimInstance.h"
#include "KismetAnimationLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	CachedPawn = TryGetPawnOwner();
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = CachedPawn.Get();
	if (!Pawn)
	{
		CachedPawn = TryGetPawnOwner();
		Pawn = CachedPawn.Get();
		if (!Pawn) return;
	}

	const FVector Velocity = Pawn->GetVelocity();
	Speed = Velocity.Size();
	Direction = UKismetAnimationLibrary::CalculateDirection(Velocity, Pawn->GetActorRotation());

	if (ACharacter* Character = Cast<ACharacter>(Pawn))
	{
		if (const UCharacterMovementComponent* MovementComponent = Character->GetCharacterMovement())
		{
			bIsInAir = MovementComponent->IsFalling();
		}
	}
}
