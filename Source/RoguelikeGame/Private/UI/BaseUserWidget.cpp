// Copyright Samuel Reitich 2022

#include "UI/BaseUserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

void UBaseUserWidget::UpdateDisplayedHealth(int Health)
{
    // Update the text widget that displays health. The passed health parameter has to be converted from an int to an FString to FText to be passed into SetText().
    DisplayedHealth->SetText(FText::FromString(FString::FromInt(Health)));
}