// Copyright Burnt Shrimp

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CaelUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CAEL_API UCaelUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
