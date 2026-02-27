#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

class UTextBlock;

UCLASS()
class PONGV1_API UScoreWidget : public UUserWidget
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdatePlayerScore(int32 NewScore);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateEnemyScore(int32 NewScore);

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreText;    // Player score

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreTextE;   // Enemy score
};