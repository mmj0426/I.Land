// Fill out your copyright notice in the Description page of Project Settings.


#include "ILAnimInstance.h"

UILAnimInstance::UILAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	IsInAir = false;
	IsFlying = false;
}

void UILAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		auto Player = Cast<ACharacter>(Pawn);
		if (Player)
		{
			IsInAir = Player->GetMovementComponent()->IsFalling();
			IsFlying = Player->GetMovementComponent()->IsFlying();
		}
	}
}