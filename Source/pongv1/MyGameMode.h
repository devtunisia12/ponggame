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

protected:
    virtual void BeginPlay() override;

public:

    UFUNCTION(BlueprintCallable)
    void AddScore();

    void SpawnBall();

    void AddScoreenemy();

private:
    int32 PlayerScore = 0;
    int32 EnemyScore = 0;


    UPROPERTY()
    UScoreWidget* ScoreWidgetInstance;  

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UScoreWidget> ScoreWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AMyBall> BallClass;

    FTimerHandle RespawnTimer;
};