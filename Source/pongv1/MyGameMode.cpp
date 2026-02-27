#include "MyGameMode.h"
#include "MyBall.h"
#include "Kismet/GameplayStatics.h"
#include "AIPaddle.h"
#include "ScoreWidget.h"
#include "Blueprint/UserWidget.h"

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    SpawnBall();
    ScoreWidgetInstance = CreateWidget<UScoreWidget>(GetWorld(), ScoreWidgetClass);
    ScoreWidgetInstance->AddToViewport();

}

void AMyGameMode::AddScore()
{
    PlayerScore++;

    UE_LOG(LogTemp, Warning, TEXT("Score: %d"), PlayerScore);

    if (ScoreWidgetInstance)
    {
        ScoreWidgetInstance->UpdateScore(PlayerScore);
    }

    GetWorld()->GetTimerManager().SetTimer(
        RespawnTimer,
        this,
        &AMyGameMode::SpawnBall,
        3.0f,
        false
    );
}

void AMyGameMode::SpawnBall()
{
    if (!BallClass) return;

    FVector SpawnLocation(760.f, 590.f, 0.f);
    FRotator SpawnRotation = FRotator::ZeroRotator;

    AMyBall* NewBall = GetWorld()->SpawnActor<AMyBall>(
        BallClass,
        SpawnLocation,
        SpawnRotation
    );

    if (!NewBall) return;

    TArray<AActor*> FoundAIPaddles;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPaddle::StaticClass(), FoundAIPaddles);

    for (AActor* Actor : FoundAIPaddles)
    {
        AAIPaddle* AIPaddle = Cast<AAIPaddle>(Actor);
        if (AIPaddle)
        {
            AIPaddle->SetTargetBall(NewBall);
        }
    }
}