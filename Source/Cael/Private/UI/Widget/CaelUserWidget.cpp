// Copyright Burnt Shrimp


#include "UI/Widget/CaelUserWidget.h"

void UCaelUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
