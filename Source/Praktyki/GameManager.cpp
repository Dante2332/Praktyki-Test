// Copyright 2025 Teyon. All Rights Reserved.


#include "GameManager.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
		EndLap(); 
	}
	
	CurrentLap++;
	if (CurrentLap > TargetLapCount)
	{
		EndRace();
	}
}

void AGameManager::UpdateLapTime()
{
	CurrentLapTime = GetWorld()->GetTimeSeconds() - CrossLineTime;
}

void AGameManager::EndRace()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("RaceEnded"));
}


void AGameManager::EndLap()
{
	LastLapTime = CurrentLapTime;
	
}
