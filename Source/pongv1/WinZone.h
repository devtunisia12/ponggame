#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WinZone.generated.h"

UCLASS()
class PONGV1_API AWinZone : public AActor
{
    GENERATED_BODY()

public:
    AWinZone();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadWrite,meta=(BindWidget))
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
