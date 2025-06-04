// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class AVehicle;

UCLASS()
class PRAKTYKI_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:

	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	AVehicle* ControlledVehicle;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AVehicle> VehicleToSpawn;

	void SpawnVehicle();
	void SetCamera();
};
