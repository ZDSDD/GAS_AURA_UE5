// Copyright Sadowy Games


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& ControllerParams)
{
	PlayerController = ControllerParams.PlayerController;
	PlayerState = ControllerParams.PlayerState;
	AbilitySystemComponent = ControllerParams.AbilitySystemComponent;
	AttributeSet = ControllerParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
}
