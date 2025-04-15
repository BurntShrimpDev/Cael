// Copyright Burnt Shrimp


#include "Character/CaelPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/CaelPlayerState.h"

ACaelPlayerCharacter::ACaelPlayerCharacter()
{

	// Prevent character rotation with controller directly
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.f, 0.f);

	// Spring Arm Setup
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 450.f;	
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritYaw = true;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->SocketOffset = FVector(0.f, 50.f, 0.f);
	CameraBoom->bDoCollisionTest = true;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->CameraLagSpeed = 12.f;

	// Camera Setup
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;
	FollowCamera->FieldOfView = 95.f;
	
}

void ACaelPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability Actor Info for Server
	InitAbilityActorInfo();
	
}

void ACaelPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init Ability Actor Info for Client
	InitAbilityActorInfo();
	
}

void ACaelPlayerCharacter::InitAbilityActorInfo()
{
	ACaelPlayerState* CaelPlayerState = GetPlayerState<ACaelPlayerState>();
	check(CaelPlayerState);
	CaelPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(CaelPlayerState, this);
	AbilitySystemComponent = CaelPlayerState->GetAbilitySystemComponent();
	AttributeSet = CaelPlayerState->GetAttributeSet();


}
