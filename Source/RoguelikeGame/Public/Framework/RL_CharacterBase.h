// Copyright Samuel Reitich 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RL_CharacterBase.generated.h"

UCLASS()
class ROGUELIKEGAME_API ARL_CharacterBase : public ACharacter
{
	GENERATED_BODY()

// Public functions.
public:

	// Sets default values for this character's properties.
	ARL_CharacterBase();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* Getter for player health. */
	UFUNCTION(BlueprintPure, Category="Player")
	FORCEINLINE int GetHealth() const { return Health; }

	/* Setter for player health. */
	UFUNCTION(BlueprintCallable, Category="Player")
	void SetHealth(int NewHealth);


// Protected functions.
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the player presses the interact key. Calls the interfaced Interact() function on valid overlapping actors.
	void OnInteract();


// Private variables.
private:

	// Player's current health.
	UPROPERTY(VisibleAnywhere, Category = "Player")
	int Health;

};
