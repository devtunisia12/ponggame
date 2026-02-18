#include "MyGameMode.h"
#include "MyBall.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    SpawnBall();
}

void AMyGameMode::AddScore()
{
    PlayerScore++;

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
        FVector SpawnLocation = FVector(760.f, 590.f, 0.f); // center of map
        FRotator SpawnRotation = FRotator::ZeroRotator;

        GetWorld()->SpawnActor<AMyBall>(
            BallClass,
            SpawnLocation,
            SpawnRotation
        );
    }
}
