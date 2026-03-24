#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBall.generated.h"

UCLASS()
class PONGV1_API AMyBall : public AActor
{
    GENERATED_BODY()

public:
    AMyBall();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Score variable exposed to Blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    int32 PlayerScore = 0;

    // Function to update UMG Widget (implemented in Blueprint)
    UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void UpdateScoreWidget();

    //Variables for Ball Movement and Boundaries
    UPROPERTY(EditAnywhere)
    float Speed = 1000.f;

    UPROPERTY(EditAnywhere)
    float MinX = 290.f;

    UPROPERTY(EditAnywhere)
    float MaxX = 1190.f;

    UPROPERTY(EditAnywhere)
    float MinY = -1190.f;

    UPROPERTY(EditAnywhere)
    float MaxY = 1320.f;

private:
    FVector Velocity;
};
