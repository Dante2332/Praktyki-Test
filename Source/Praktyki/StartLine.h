// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StartLine.generated.h"

class AGameManager;
class UBoxComponent;

UCLASS()
class PRAKTYKI_API AStartLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStartLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LineMesh;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	AGameManager* GameManager;
};
