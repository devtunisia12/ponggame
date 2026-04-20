#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaddleMove.generated.h"

UCLASS()
class PONGV1_API APaddleMove : public APawn
{
    GENERATED_BODY()

public:
    APaddleMove();
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
    virtual void BeginPlay() override;

    void MoveForward(float Value);

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Speed = 600.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MinX = 380.f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MaxX = 1130.f;
};
