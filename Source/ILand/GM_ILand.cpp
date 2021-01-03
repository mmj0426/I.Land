// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_ILand.h"
#include "PlayerCharacter.h"
#include "PC_ILand.h"

AGM_ILand::AGM_ILand()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = APC_ILand::StaticClass();
}