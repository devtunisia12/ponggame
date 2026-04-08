#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIPaddle.generated.h"

UCLASS()
class PONGV1_API AAIPaddle : public APawn
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

public:
    AAIPaddle();

    void SetTargetBall(AActor* NewBall) { TargetBall = NewBall; }
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY()
    AActor* TargetBall;
    float ReactionTime = 0.5f;

    UPROPERTY(EditAnywhere, Category = "AI")
    float MoveSpeed = 800.f;

    UPROPERTY(EditAnywhere, Category = "AI")
    float MinX = -300.f;

    UPROPERTY(EditAnywhere, Category = "AI")
    float MaxX = 300.f;

    FVector FixedLocation;

    void UpdateTargetBall();

    float CurrentError = 0.f;
    float TimeSinceLastUpdate = 0.f;
};
