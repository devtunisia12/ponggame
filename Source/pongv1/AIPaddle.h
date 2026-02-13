#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIPaddle.generated.h"

class AMyBall;

UCLASS()
class PONGV1_API AAIPaddle : public APawn
{
    GENERATED_BODY()

public:
    AAIPaddle();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Reference to ball
    UPROPERTY(EditAnywhere)
    AMyBall* TargetBall;

private:
    UPROPERTY(EditAnywhere)
    float MoveSpeed = 800.f;
};
