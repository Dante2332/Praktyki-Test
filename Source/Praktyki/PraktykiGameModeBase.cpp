// Fill out your copyright notice in the Description page of Project Settings.


#include "PraktykiGameModeBase.h"

#include "PlayerPawn.h"

APraktykiGameModeBase::APraktykiGameModeBase()
{
	DefaultPawnClass = APlayerPawn::StaticClass();

}
