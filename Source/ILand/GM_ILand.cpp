// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ILand.h"
#include "PlayerCharacter.h"
#include "PC_ILand.h"
#include "Blueprint/UserWidget.h"

AGM_ILand::AGM_ILand()
{
	static ConstructorHelpers::FClassFinder<ACharacter> PlayerCharacter(TEXT("/Game/ILand/Characters/Player.Player_C"));
	DefaultPawnClass = PlayerCharacter.Class;

	PlayerControllerClass = APC_ILand::StaticClass();

	static ConstructorHelpers::FClassFinder<UUserWidget>
		UI_TimeText(TEXT("/Game/ILand/UMG/WidgetBP_StageTime.WidgetBP_StageTime_C"));

	TimeWidgetClass = UI_TimeText.Class;
	
}

void AGM_ILand::BeginPlay()
{
	Super::BeginPlay();

	if (TimeWidgetClass != nullptr)
	{
		if (CreateWidget<UUserWidget>(GetWorld(), TimeWidgetClass) != nullptr)
		{
			CreateWidget<UUserWidget>(GetWorld(), TimeWidgetClass)->AddToViewport();
		}
	}
}

void AGM_ILand::StagePlayTime(TSubclassOf<UUserWidget>NewWidgetClass)
{

}