// No arquivo .h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyStaticMeshCreator.generated.h"

UCLASS()
class MYPROJECT_API AMyStaticMeshCreator : public AActor
{
    GENERATED_BODY()
    
public:    
    AMyStaticMeshCreator();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* StaticMeshComponent;
};