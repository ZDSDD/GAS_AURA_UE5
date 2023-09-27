// Copyright Sadowy Games


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	this->WidgetController = InWidgetController;
	this->WidgetControllerSet();
}
