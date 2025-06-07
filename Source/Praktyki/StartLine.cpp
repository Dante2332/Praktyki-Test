// Copyright 2025 Teyon. All Rights Reserved.


#include "StartLine.h"

#include "EngineUtils.h"
#include "GameManager.h"
#include "Components/BoxComponent.h"

// Sets default values
AStartLine::AStartLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LineMesh = CreateDefaultSubobject<UStaticMeshComponent>("LineMesh");
	RootComponent = LineMesh;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(RootComponent);
	
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	BoxCollision->SetGenerateOverlapEvents(true);
	
}

// Called when the game starts or when spawned
void AStartLine::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AStartLine::OnOverlapBegin);
	for (TActorIterator<AGameManager> It(GetWorld()); It; ++It)
	{
		GameManager = *It;
		break;
	}
}

void AStartLine::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GameManager->OnLapCrossed();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Lap crossed");
}

// Called every frame
void AStartLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


