// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class PRAKTYKI_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE void SetIsCounting(bool bNew) { bIsCounting = bNew; }

private:
	bool bIsCounting = false;
	int TargetLapCount;
	int CurrentLap;
	
	float CurrentLapTime;
	float StartLapTime;
	float LastLapTime;

	void UpdateLapTime();
};
