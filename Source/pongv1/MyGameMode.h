#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

class UScoreWidget;
class AMyBall;

UCLASS()
class PONGV1_API AMyGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void AddScore();

    void SpawnBall();

private:
    int32 PlayerScore = 0;

    UPROPERTY()
    UScoreWidget* ScoreWidgetInstance;   // ❗ NOT EditAnywhere

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UScoreWidget> ScoreWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AMyBall> BallClass;

    FTimerHandle RespawnTimer;
};