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

    void AddScore();

    void SpawnBall();

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> ScoreWidgetClass;

    UScoreWidget* ScoreWidgetInstance;

private:
    int32 PlayerScore = 0;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class AMyBall> BallClass;

    FTimerHandle RespawnTimer;
};
