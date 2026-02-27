#include "ScoreWidget.h"
#include "Components/TextBlock.h"

void UScoreWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(0));
    }
}

void UScoreWidget::UpdateScore(int32 NewScore)
{
    if (!ScoreText) return;

    ScoreText->SetText(FText::AsNumber(NewScore));
}