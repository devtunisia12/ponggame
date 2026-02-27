#include "GoalEnemy.h"
#include "Components/BoxComponent.h"
#include "MyBall.h"
#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"

AGoalEnemy::AGoalEnemy()
{
    PrimaryActorTick.bCanEverTick = false;

    TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
    RootComponent = TriggerZone;

    TriggerZone->InitBoxExtent(FVector(200.f, 200.f, 100.f));
    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionObjectType(ECC_WorldStatic);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Overlap);
}

void AGoalEnemy::BeginPlay()
{
    Super::BeginPlay();
    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AGoalEnemy::OnOverlapBegin);
}

void AGoalEnemy::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->IsA(AMyBall::StaticClass()))
    {
        AMyGameMode* GM = Cast<AMyGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
        if (GM)
        {
            GM->AddScoreenemy();  // Add to enemy score
        }

        OtherActor->Destroy();
    }
}