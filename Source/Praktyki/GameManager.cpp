// Copyright 2025 Teyon. All Rights Reserved.


#include "GameManager.h"


AGameManager::AGameManager()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGameManager::OnLapCrossed()
{
	CrossLineTime = GetWorld()->GetTimeSeconds();
	if (!bIsCounting)
	{
		 GetWorld()->GetTimerManager().SetTimer(LapTimerHandle, this, &AGameManager::UpdateLapTime, GetWorld()->GetDeltaSeconds(), true);
		bIsCounting = true;
	}
	else
	{
		GetWorldTimerManager().PauseTimer(LapTimerHandle);
		EndLap();
		GetWorldTimerManager().UnPauseTimer(LapTimerHandle);
	}
	
	CurrentLap++;
	if (CurrentLap > TargetLapCount)
	{
		BestLapTime = FMath::Min(LapTimes);
		OnRaceEnd.Broadcast();
	}
}

void AGameManager::UpdateLapTime()
{
	CurrentLapTime = GetWorld()->GetTimeSeconds() - CrossLineTime;
}



void AGameManager::EndLap()
{
	LastLapTime = CurrentLapTime;
	LapTimes.Add(LastLapTime);
	
}
