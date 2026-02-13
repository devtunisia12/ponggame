#include "AIPaddle.h"
#include "MyBall.h"

AAIPaddle::AAIPaddle()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAIPaddle::BeginPlay()
{
    Super::BeginPlay();
}

void AAIPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!TargetBall) return;

    FVector PaddleLocation = GetActorLocation();
    FVector BallLocation = TargetBall->GetActorLocation();

    float Direction = 0.f;

    if (BallLocation.X > PaddleLocation.X)
    {
        Direction = 1.f;
    }
    else if (BallLocation.X < PaddleLocation.X)
    {
        Direction = -1.f;
    }

    PaddleLocation.X += Direction * MoveSpeed * DeltaTime;

    SetActorLocation(PaddleLocation);
}
