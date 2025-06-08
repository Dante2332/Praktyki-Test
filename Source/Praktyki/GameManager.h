// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRaceEnd);

UCLASS()
class PRAKTYKI_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();
	
	virtual void Tick(float DeltaTime) override;
	
	void EndLap();
	void OnLapCrossed();

	UPROPERTY(BlueprintAssignable)
	FOnRaceEnd OnRaceEnd;
	
	FORCEINLINE void SetIsCounting(bool bNew) { bIsCounting = bNew; }

protected:
	
	virtual void BeginPlay() override;

	
private:
	
	FTimerHandle LapTimerHandle;
	
	bool bIsCounting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int TargetLapCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int CurrentLap;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float CurrentLapTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float LastLapTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float BestLapTime;
	
	float CrossLineTime;
	TArray<float> LapTimes;

	
	void UpdateLapTime();
};
