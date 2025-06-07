// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class AVehicle;
class UInputAction;


UCLASS()
class PRAKTYKI_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

	virtual void Tick(float DeltaTime) override;
	
protected:

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:	
	// Car setup
	UPROPERTY(VisibleAnywhere)
	AVehicle* ControlledVehicle;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AVehicle> VehicleToSpawn;

	void SpawnVehicle();
	void SetCamera();


	//Enhanced Input
	UPROPERTY(EditAnywhere)
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere)
	UInputAction* AccelerateAction;

	UPROPERTY(EditAnywhere)
	UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere)
	UInputAction* TurnAction;

	UPROPERTY(EditAnywhere)
	UInputAction* CameraAction;

	//UI
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> PlayerWidgetClass;
	UPROPERTY(EditAnywhere)
	UUserWidget* PlayerWidget;
	
	void HandleAcceleration(const FInputActionValue& Value);
	void HandleBrake(const FInputActionValue& Value);
	void HandleTurn(const FInputActionValue& Value);
	void HandleCamera();
};
