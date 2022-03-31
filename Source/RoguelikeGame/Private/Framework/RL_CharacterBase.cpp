// Copyright Samuel Reitich 2022

#include "Framework/RL_CharacterBase.h"

#include "InteractInterface.h"

#define OUT

ARL_CharacterBase::ARL_CharacterBase()
{
 	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ARL_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARL_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARL_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ARL_CharacterBase::OnInteract);

}

void ARL_CharacterBase::SetHealth(int NewHealth)
{
	// Don't let health go below 0 or above 100.
	Health = FMath::Clamp(NewHealth, 0, 100);
}

void ARL_CharacterBase::OnInteract()
{
	// Stores overlapping actors.
	TArray <AActor*> OverlappingActors;

	// Get all actors overlapping the player.
	GetOverlappingActors(OUT OverlappingActors);

	// For every overlapping actor...
	for (AActor* InteractedActor : OverlappingActors)
	{
		// If the overlapping actor uses the interact interface...
		if (Cast<IInteractInterface>(InteractedActor))
		{
			// Call the actor's interact function.
			Cast<IInteractInterface>(InteractedActor)->Interact();
		}
	}
}