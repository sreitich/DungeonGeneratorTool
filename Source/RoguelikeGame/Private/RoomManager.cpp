// Copyright Samuel Reitich 2022

#include "RoomManager.h"

#include "EntranceAnchor.h"
#include "ExitAnchor.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"

ARoomManager::ARoomManager()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ARoomManager::BeginPlay()
{
	Super::BeginPlay();


}

void ARoomManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoomManager::LoadRooms()
{
	// Unload every level except for this one.
	for (FName LevelName : AllRooms)
	{
		if (LevelName != ThisRoom)
		{
			FLatentActionInfo LatentInfo;
			UGameplayStatics::UnloadStreamLevel(this, LevelName, LatentInfo, false);
		}
	}

	// If this room has exits...
	if (RoomExits.Num() > 0)
	{
		// For every exit in this room...
		for (AExitAnchor* Exit : RoomExits)
		{
			// Get a random room from the list of possible next rooms.
			FName RoomToLoad = PossibleNextRooms[rand() % PossibleNextRooms.Num()];

			// Define a lambda function to be called when the next room finishes loading. This function needs access to the currently iterated Exit (passed by ref) and the RoomToLoad name (passed by copy).
			auto AlignmentLambda = [&, RoomToLoad] () -> void
			{
				if (GetEntranceAnchor(RoomToLoad))
				{
					// Get the next room's entrance anchor.
					AEntranceAnchor* EntranceAnchor = GetEntranceAnchor(RoomToLoad);

					// Give the entrance anchor the exit that leads to it so the doors close after entering the room.
					EntranceAnchor->ExitToThis = Exit;

					// Align the next room's entrance anchor to this room's exit anchor.
					GetEntranceAnchor(RoomToLoad)->SetActorTransform(Exit->GetActorTransform(), false);
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("Failed"));
				}
			};

			// Load the next room.
			FLatentActionInfo LatentInfo;
			UGameplayStatics::LoadStreamLevel(this, RoomToLoad, true, false, LatentInfo);

			// Bind the alignment lambda to be called when this level finished loading.
			// UGameplayStatics::GetStreamingLevel(this, RoomToLoad)->OnLevelLoaded.AddDynamic(this, AlignmentLambda);

			// Get the next room's entrance anchor.
			AEntranceAnchor* EntranceAnchor = GetEntranceAnchor(RoomToLoad);

			// Give the entrance anchor the exit that leads to it so the doors close after entering the room.
			EntranceAnchor->ExitToThis = Exit;

			// Align the next room's entrance anchor to this room's exit anchor.
			GetEntranceAnchor(RoomToLoad)->SetActorTransform(Exit->GetActorTransform(), false);
		}
	}
}