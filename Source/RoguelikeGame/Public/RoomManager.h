// Copyright Samuel Reitich 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomManager.generated.h"

UCLASS()
class ROGUELIKEGAME_API ARoomManager : public AActor
{
	GENERATED_BODY()

// Public functions.
public:

	// Sets default values for this actor's properties.
	ARoomManager();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Loads the next potential rooms when a player enters this manager's room.
	UFUNCTION()
	void LoadRooms();

	// Returns a given level's entrance anchor through a blueprint interface.
	UFUNCTION(BlueprintImplementableEvent)
	class AEntranceAnchor* GetEntranceAnchor(FName LevelName);


// Protected functions.
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;


// Protected variables.
protected:

	// An array of every level's name to unload each level.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Room Manager")
	TArray<FName> AllRooms;

	// An array of rooms that this room can lead to.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room Manager")
	TArray<FName> PossibleNextRooms;

	// An array of this room's exits.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room Manager")
	TArray<class AExitAnchor*> RoomExits;

	// This room's entrance.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room Manager")
	class AEntranceAnchor* RoomEntrance;

	// This manager's room's name.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room Manager")
	FName ThisRoom;
};
