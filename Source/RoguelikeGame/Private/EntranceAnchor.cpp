// Copyright Samuel Reitich 2022

#include "EntranceAnchor.h"

#include "RoomManager.h"
#include "ExitAnchor.h"
#include "Framework/RL_CharacterBase.h"

#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AEntranceAnchor::AEntranceAnchor()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set up components.
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Scene Component"));
	SetRootComponent(RootSceneComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootSceneComponent);

}

void AEntranceAnchor::BeginPlay()
{
	Super::BeginPlay();
	
	// Bind the box collision to the overlap function.
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEntranceAnchor::OnBoxBeginOverlap);
}

void AEntranceAnchor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEntranceAnchor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ExitToThis)
	{
		// Close this room's entrance doors.
		ExitToThis->CloseDoors();
	}

	if (Cast<ARL_CharacterBase>(OtherActor))
	{
		RoomManager->LoadRooms();
	}
}