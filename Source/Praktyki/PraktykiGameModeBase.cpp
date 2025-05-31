// Fill out your copyright notice in the Description page of Project Settings.


#include "PraktykiGameModeBase.h"

#include "CarPawn.h"

APraktykiGameModeBase::APraktykiGameModeBase()
{
	DefaultPawnClass = ACarPawn::StaticClass();
}
