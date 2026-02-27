#include "AIPaddle.h"
#include "Kismet/GameplayStatics.h"

AAIPaddle::AAIPaddle()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAIPaddle::BeginPlay()
{
    Super::BeginPlay();

    FixedLocation = GetActorLocation();

    UpdateTargetBall();
}

void AAIPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!TargetBall) return;

    FVector PaddleLocation = GetActorLocation();
    FVector BallLocation = TargetBall->GetActorLocation();

    // Add random offset for "stupidity"
    float Error = FMath::RandRange(-100.f, 100.f);

    // Target position the AI tries to reach smoothly
    float TargetX = BallLocation.X + Error;

    // Smoothly interpolate to the target X
    PaddleLocation.X = FMath::FInterpTo(PaddleLocation.X, TargetX, DeltaTime, MoveSpeed / 100.f);

    // Keep Y and Z fixed
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
