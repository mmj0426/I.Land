// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "ILAnimInstance.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 400.0f;

	GetCapsuleComponent()->SetCapsuleRadius(75.0f);
	GetCapsuleComponent()->SetCapsuleHalfHeight(110.0f);
	GetCapsuleComponent()->SetRelativeLocation(FVector(0.0f, 0.0f, 125.0f));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->TargetArmLength = 600.0f;
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 60.0f), FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		SM_Player(TEXT("/Game/TeachersMarketplace/Assets/Character/Character/Mesh/epicCharacter_Rig.epicCharacter_Rig"));
	if (SM_Player.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM_Player.Object);
	}
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -105.0f), FRotator(0.0f, -90.0f, 0.0f));

	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance>
		Anim_Player(TEXT("/Game/ILand/Animations/AnimBP_PlayerCharacter.AnimBP_PlayerCharacter_C"));
	if (Anim_Player.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(Anim_Player.Class);
	}

	IsFlying = false;
	TouchCount = 0;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAction(TEXT("Touch"), EInputEvent::IE_Pressed, this, &APlayerCharacter::DivideTouch);
	PlayerInputComponent->BindAction(TEXT("Flight"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Flight);
}

void APlayerCharacter::MoveForward(float NewAxisValue)
{
	if (Controller != nullptr && NewAxisValue != 0.0f)
	{
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
	}
}

void APlayerCharacter::MoveRight(float NewAxisValue)
{
	if (Controller != nullptr && NewAxisValue != 0.0f)
	{
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
	}
}

void APlayerCharacter::Jump()
{
	ACharacter::Jump();
}

void APlayerCharacter::Flight()
{
	if (IsFlying == true)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
	}
	else
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}
	IsFlying = !IsFlying;

}