#include "ScoreWidget.h"
#include "Components/TextBlock.h"

void UScoreWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(0));
    }

    if (ScoreTextE)
    {
        ScoreTextE->SetText(FText::AsNumber(0));
    }

}

void UScoreWidget::UpdatePlayerScore(int32 NewScore)
{
    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(NewScore));
    }
}

void UScoreWidget::UpdateEnemyScore(int32 NewScore)
{
    if (ScoreTextE)
    {
        ScoreTextE->SetText(FText::AsNumber(NewScore));
    }
}