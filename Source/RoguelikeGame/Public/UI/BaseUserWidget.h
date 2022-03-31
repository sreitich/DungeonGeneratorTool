// Copyright Samuel Reitich 2022

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIKEGAME_API UBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()

// Public functions.
public:

	// Updates the player's health on their HUD.
	UFUNCTION()
	void UpdateDisplayedHealth(int Health);


// Protected widgets.
protected:

	// The player's current health.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* DisplayedHealth;

	// How many rooms the player has entered (inclusive).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* DisplayedRoomNumber;


};
