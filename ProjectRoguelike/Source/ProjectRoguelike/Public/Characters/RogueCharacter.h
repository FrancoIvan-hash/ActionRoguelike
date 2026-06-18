// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RogueCharacter.generated.h"

UCLASS()
class PROJECTROGUELIKE_API ARogueCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARogueCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rogue | Components")
	TObjectPtr<class USpringArmComponent> SpringArmComponet{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rogue | Components")
	TObjectPtr<class UCameraComponent> CameraComponent{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<class UInputAction> MoveAction{ nullptr };

	UPROPERTY(EditDefaultsOnly, Category = Input)
	TObjectPtr<UInputAction> LookAction{ nullptr };

	void Move(const struct FInputActionValue& Value);
	// also have FInputActionInstance
	void Look(const struct FInputActionInstance& Value);


private:

	

};
