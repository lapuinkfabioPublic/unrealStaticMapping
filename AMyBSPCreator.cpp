//Fabio Leandro Lapuinka 06/09/2025
// No arquivo .h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BrushComponent.h"
#include "MyBSPCreator.generated.h"

UCLASS()
class MYPROJECT_API AMyBSPCreator : public AActor
{
    GENERATED_BODY()
    
public:    
    AMyBSPCreator();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UBrushComponent* BrushComponent;
};
