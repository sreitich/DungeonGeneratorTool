// Copyright Samuel Reitich 2022

#pragma once

#include "InteractInterface.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitAnchor.generated.h"

UCLASS()
class ROGUELIKEGAME_API AExitAnchor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
// Public functions.
public:

	// Sets default values for this actor's properties.
	AExitAnchor();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Called when the player interacts with an exit.
	virtual void Interact() override;

	// Opens this exit's doors.
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OpenDoors();

	// Closes this exit's doors.
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void CloseDoors();


// Protected functions.
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;


// Protected components.
protected:

	// Root of this actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class USceneComponent* RootSceneComponent;

	// Used to detect when a player wants to leave a room.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class UBoxComponent* BoxCollision;

	// The right-side exit door to open.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class UStaticMeshComponent* RightDoor;

	// The left-side exit door to open.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class UStaticMeshComponent* LeftDoor;

};
