// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ILand.h"
#include "Animation/AnimInstance.h"
#include "ILAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ILAND_API UILAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public : 
	UILAnimInstance();

private : 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsFlying;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsSwimming;

public : 

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	void SetPawnSpeed(float NewPawnSpeed) { CurrentPawnSpeed = NewPawnSpeed; }
};
