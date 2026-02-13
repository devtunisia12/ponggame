#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "mainmenucode.generated.h"

UCLASS()
class PONGV1_API Umainmenucode : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    // Bind your Start button from Blueprint
    UPROPERTY(meta = (BindWidget))
    UButton* StartBtn;

    // Function to be called when Start button is clicked
    UFUNCTION()
    void OnStartClicked();
};
