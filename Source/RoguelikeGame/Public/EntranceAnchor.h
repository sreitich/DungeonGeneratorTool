// Copyright Samuel Reitich 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EntranceAnchor.generated.h"

UCLASS()
class ROGUELIKEGAME_API AEntranceAnchor : public AActor
{
	GENERATED_BODY()
	
// Public functions.
public:

	// Sets default values for this actor's properties.
	AEntranceAnchor();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;


// Public variables.
public:

	// A pointer to the exit that led to this entrance so that its doors can be closed. This is set in the room manager.
	class AExitAnchor* ExitToThis;


// Protected functions.
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


// Protected variables.
protected:

	// A pointer to this room's room manager.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Entrance Anchor")
	class ARoomManager* RoomManager;


// Protected components.
protected:

	// Root of this actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class USceneComponent* RootSceneComponent;

	// Used to detect when a player enters a room.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	class UBoxComponent* BoxCollision;

};
