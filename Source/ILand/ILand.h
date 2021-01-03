// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(ILand, Log, All);

#define IL_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

#define IL_S(Verbosity) UE_LOG(ILand, Verbosity, TEXT("%s"), *IL_CALLINFO)

#define ILLOG(Verbosity,Format, ...) UE_LOG(ILand, Verbosity, TEXT("%s %s"), *IL_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

//ILCHECK ��ũ�θ� �߰� : ��Ÿ�ӿ��� ������ �߻��� �� ������ �����α� �Ѹ��� �Լ� ��ȯ
#define ILCHECK(Expr, ...){if(!(Expr)) {ILLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}
