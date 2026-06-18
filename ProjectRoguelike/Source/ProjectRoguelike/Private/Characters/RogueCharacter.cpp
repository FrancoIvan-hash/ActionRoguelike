// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RogueCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"


// Sets default values
ARogueCharacter::ARogueCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating the components
	SpringArmComponet = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	check(SpringArmComponet != nullptr);
	SpringArmComponet->SetupAttachment(RootComponent);
	SpringArmComponet->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	check(SpringArmComponet != nullptr);
	CameraComponent->SetupAttachment(SpringArmComponet);

}

// Called when the game starts or when spawned
void ARogueCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ARogueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARogueCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARogueCharacter::Move);
	EnhancedComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARogueCharacter::Look);

}

void ARogueCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementValue = Value.Get<FVector2D>();

	const float YawRot = GetControlRotation().Yaw;
	const FRotator YawRotator = FRotator(0.f, YawRot, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
	const FVector RightDirection = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);

	AddMovementInput(ForwardDirection, MovementValue.Y);
	AddMovementInput(RightDirection, MovementValue.X);
}

void ARogueCharacter::Look(const FInputActionInstance& Value)
{
	const FVector2D LookValue = Value.GetValue().Get<FVector2D>();

	AddControllerPitchInput(LookValue.Y);
	AddControllerYawInput(LookValue.X);
}
