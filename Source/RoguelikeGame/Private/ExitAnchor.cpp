// Copyright Samuel Reitich 2022

#include "ExitAnchor.h"

#include "Components/BoxComponent.h"

AExitAnchor::AExitAnchor()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set up components.
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Scene Component"));
	SetRootComponent(RootSceneComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(RootSceneComponent);

	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Door"));
	RightDoor->SetupAttachment(RootSceneComponent);

	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Door"));
	LeftDoor->SetupAttachment(RootSceneComponent);
}

void AExitAnchor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExitAnchor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExitAnchor::Interact()
{
	// Handles animations for opening the doors.
	OpenDoors();
}