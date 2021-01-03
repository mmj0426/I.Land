// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_ILand.h"

void APC_ILand::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}