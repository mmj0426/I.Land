// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ILand.h"
#include "GameFramework/PlayerController.h"
#include "PC_ILand.generated.h"

/**
 * 
 */
UCLASS()
class ILAND_API APC_ILand : public APlayerController
{
	GENERATED_BODY()
	
protected : 
	virtual void BeginPlay() override;
};
