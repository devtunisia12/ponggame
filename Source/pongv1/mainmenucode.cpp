// Fill out your copyright notice in the Description page of Project Settings.


#include "mainmenucode.h"
#include "Kismet/GameplayStatics.h"


void Umainmenucode::NativeConstruct()
{
    Super::NativeConstruct();

    // Bind the button click event
    if (StartBtn)
    {
        StartBtn->OnClicked.AddDynamic(this, &Umainmenucode::OnStartClicked);
    }
}

void Umainmenucode::OnStartClicked()
{
    if (GetWorld())
    {
        // Replace "LevelName" with your level's name
        UGameplayStatics::OpenLevel(GetWorld(), FName("gamelvBot"));
    }
}
