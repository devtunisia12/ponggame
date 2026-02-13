#include "WinZone.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "MyBall.h"
#include "Components/TextBlock.h" // This is correct for UTextBlock


AWinZone::AWinZone()
{
    PrimaryActorTick.bCanEverTick = false;

    TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
    RootComponent = TriggerZone;

    TriggerZone->InitBoxExtent(FVector(200.f, 200.f, 100.f));
    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionObjectType(ECC_WorldStatic);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void AWinZone::BeginPlay()
{
    Super::BeginPlay();
    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AWinZone::OnOverlapBegin);
}

void AWinZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->IsA(AMyBall::StaticClass()))
    {
        AMyBall* Ball = Cast<AMyBall>(OtherActor);
        if (Ball)
        {
            // Increase score
            Ball->PlayerScore += 1;

            // Call Blueprint event to update the UMG widget
            Ball->UpdateScoreWidget();

            // Optional: debug message
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(
                    -1, 3.f, FColor::Yellow,
                    FString::Printf(TEXT("Ball entered Win Zone! Score: %d"), Ball->PlayerScore)
                );
            }
        }
    }
}
