#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIPaddle.generated.h"

UCLASS()
class PONGV1_API AAIPaddle : public APawn
{
    GENERATED_BODY()

public:
    AAIPaddle();

    void SetTargetBall(AActor* NewBall) { TargetBall = NewBall; }

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY()
    AActor* TargetBall;
    float ReactionTime = 0.5f;
    float ReactionTimer = 0.f;

    UPROPERTY(EditAnywhere, Category = "AI")
    float MoveSpeed = 800.f;

    FVector FixedLocation;

    void UpdateTargetBall();
};
