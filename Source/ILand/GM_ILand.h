// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ILand.h"
#include "GameFramework/GameMode.h"
#include "GM_ILand.generated.h"


/**
 * 
 */
UCLASS()
class ILAND_API AGM_ILand : public AGameMode
{
	GENERATED_BODY()
	
public : 
	AGM_ILand();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UUserWidget> TimeWidgetClass;

};
