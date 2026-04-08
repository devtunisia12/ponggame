#include "AIPaddle.h"
#include "Kismet/GameplayStatics.h"

AAIPaddle::AAIPaddle()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAIPaddle::BeginPlay()
{
    Super::BeginPlay();
    CurrentError = FMath::RandRange(-100.f, 100.f);
    FixedLocation = GetActorLocation();

    UpdateTargetBall();
}

void AAIPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!TargetBall) return;

    FVector PaddleLocation = GetActorLocation();
    FVector BallLocation = TargetBall->GetActorLocation();


    TimeSinceLastUpdate += DeltaTime;

    if (TimeSinceLastUpdate >= ReactionTime)
    {
        CurrentError = FMath::RandRange(-100.f, 100.f);
        TimeSinceLastUpdate = 0.f;
    }

    float TargetX = BallLocation.X + CurrentError;

    TargetX = FMath::Clamp(TargetX, MinX, MaxX);

    PaddleLocation.X = FMath::FInterpTo(PaddleLocation.X, TargetX, DeltaTime, MoveSpeed / 100.f);

    PaddleLocation.Y = FixedLocation.Y;
    PaddleLocation.Z = FixedLocation.Z;

    SetActorLocation(PaddleLocation);
}


void AAIPaddle::UpdateTargetBall()
{
    if (!TargetBall || !TargetBall->IsValidLowLevel() || TargetBall->IsPendingKill())
    {
        TArray<AActor*> FoundBalls;
        UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Ball"), FoundBalls);

        if (FoundBalls.Num() > 0)
        {
            TargetBall = FoundBalls[0];
        }
        else
        {
            TargetBall = nullptr;
        }
    }
}
