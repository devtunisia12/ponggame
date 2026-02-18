#include "MyGameMode.h"
#include "MyBall.h"
#include "Kismet/GameplayStatics.h"
#include "AIPaddle.h"
#include "ScoreWidget.h"
#include "Engine/World.h"

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    SpawnBall();

    if (ScoreWidgetClass)
    {
        ScoreWidgetInstance = CreateWidget<UScoreWidget>(GetWorld(), ScoreWidgetClass);
        if (ScoreWidgetInstance)
        {
            ScoreWidgetInstance->AddToViewport();          
            ScoreWidgetInstance->UpdateScore(PlayerScore); 
        }
    }
}

void AMyGameMode::AddScore()
{
    PlayerScore++;

    if (ScoreWidgetInstance)
    {
        ScoreWidgetInstance->UpdateScore(PlayerScore); 
    }
    UE_LOG(LogTemp, Warning, TEXT("Score: %d"), PlayerScore);


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
    if (BallClass)
    {
        FVector SpawnLocation = FVector(760.f, 590.f, 0.f); 
        FRotator SpawnRotation = FRotator::ZeroRotator;

        AMyBall* NewBall = GetWorld()->SpawnActor<AMyBall>(
            BallClass,
            SpawnLocation,
            SpawnRotation
        );

        if (NewBall)
        {
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
    }
}

