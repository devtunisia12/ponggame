#include "MyBall.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

AMyBall::AMyBall()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyBall::BeginPlay()
{
    Super::BeginPlay();

    float XDir = FMath::RandBool() ? 1.f : -1.f;
    float YDir = FMath::FRandRange(-0.5f, 0.5f);

    Velocity = FVector(XDir, YDir, 0.f).GetSafeNormal() * Speed;
}

void AMyBall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Start = GetActorLocation();
    FVector End = Start + Velocity * DeltaTime;

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_WorldStatic, Params))
    {
        if (Hit.GetActor() && Hit.GetActor()->ActorHasTag("Wall"))
        {
            FVector Normal = Hit.ImpactNormal;
            Velocity = Velocity - 2.f * FVector::DotProduct(Velocity, Normal) * Normal;

            End = Hit.ImpactPoint + Velocity.GetSafeNormal() * 2.f;

            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, TEXT("Hit Wall!"));
            }
        }


    }

    if (End.X <= MinX || End.X >= MaxX)
    {
        Velocity.X *= -1;
        End.X = FMath::Clamp(End.X, MinX, MaxX);
    }

    if (End.Y <= MinY || End.Y >= MaxY)
    {
        Velocity.Y *= -1;
        End.Y = FMath::Clamp(End.Y, MinY, MaxY);
    }

    SetActorLocation(End);
}
