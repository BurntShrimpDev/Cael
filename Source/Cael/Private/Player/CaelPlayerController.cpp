// Copyright Burnt Shrimp


#include "Player/CaelPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ACaelPlayerController::ACaelPlayerController()
{
	// For future multiplayer support
	bReplicates = true;	
}

void ACaelPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(GameplayContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(GameplayContext, GameplayContextPriority);

	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameOnly InputModeData;
	//InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	//InputModeData.SetHideCursorDuringCapture(true);
	SetInputMode(InputModeData);
}

void ACaelPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACaelPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACaelPlayerController::Look);
	EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &ACaelPlayerController::StartAim);
	EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &ACaelPlayerController::StopAim);
}

void ACaelPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	
}

void ACaelPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2d LookAxis = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxis.X);
	AddPitchInput(LookAxis.Y);
	UE_LOG(LogTemp, Warning, TEXT("Look input: X=%f, Y=%f"), LookAxis.X, LookAxis.Y);
}

 void ACaelPlayerController::StartAim(const FInputActionValue& InputActionValue)
{
	
}

void ACaelPlayerController::StopAim(const FInputActionValue& InputActionValue)
{
}
