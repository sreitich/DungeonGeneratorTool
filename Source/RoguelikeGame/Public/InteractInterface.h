// Copyright Samuel Reitich 2022

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ROGUELIKEGAME_API IInteractInterface
{
	GENERATED_BODY()

public:

	virtual void Interact();

};
