#include "PaddleMove.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

APaddleMove::APaddleMove()
{
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APaddleMove::BeginPlay()
{
    Super::BeginPlay();
}

void APaddleMove::MoveForward(float Value)
{
    if (Value == 0.f) return;

    FVector Location = GetActorLocation();
    Location.X += Value * Speed * GetWorld()->GetDeltaSeconds();
    Location.X = FMath::Clamp(Location.X, MinX, MaxX);

    SetActorLocation(Location);
}

void APaddleMove::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APaddleMove::MoveForward);
}  