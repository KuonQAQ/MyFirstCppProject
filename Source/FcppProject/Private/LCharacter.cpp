// Fill out your copyright notice in the Description page of Project Settings.


#include "LCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ALCharacter::ALCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
	

}

// Called when the game starts or when spawned
void ALCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}

void ALCharacter::MoveRight(float value)
{
	AddMovementInput((GetActorRightVector()),value);
}


// Called every frame
void ALCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ALCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ALCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
}

