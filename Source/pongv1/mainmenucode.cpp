

#include "mainmenucode.h"
#include "Kismet/GameplayStatics.h"


void Umainmenucode::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartBtn)
    {
        StartBtn->OnClicked.AddDynamic(this, &Umainmenucode::OnStartClicked);
    }
}

void Umainmenucode::OnStartClicked()
{
    if (GetWorld())
    {
        UGameplayStatics::OpenLevel(GetWorld(), FName("gamelvBot"));
    }
}
