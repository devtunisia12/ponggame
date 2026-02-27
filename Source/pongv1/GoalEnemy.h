// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoalEnemy.generated.h"

UCLASS()
class PONGV1_API AGoalEnemy : public AActor
{
	GENERATED_BODY()
	
public:
    AGoalEnemy();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* TextLabel;

public:
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* TriggerZone;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);

};
