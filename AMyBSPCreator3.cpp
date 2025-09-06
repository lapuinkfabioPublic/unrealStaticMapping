// No arquivo .cpp
#include "MyBSPCreator.h"
#include "Engine/Polys.h"
#include "Components/BrushComponent.h"

AMyBSPCreator::AMyBSPCreator()
{
    PrimaryActorTick.bCanEverTick = false;
    
    // Cria um componente brush
    BrushComponent = CreateDefaultSubobject<UBrushComponent>(TEXT("BrushComponent"));
    RootComponent = BrushComponent;
    
    // Define como um cubo simples
    BrushComponent->Brush = NewObject<UModel>();
    BrushComponent->Brush->Initialize(nullptr, true);
    BrushComponent->Brush->Polys = NewObject<UPolys>();
    BrushComponent->BrushBuilder = NewObject<UCubeBrushBuilder>();
    
    UCubeBrushBuilder* CubeBuilder = Cast<UCubeBrushBuilder>(BrushComponent->BrushBuilder);
    if (CubeBuilder)
    {
        CubeBuilder->X = 500.f;
        CubeBuilder->Y = 500.f;
        CubeBuilder->Z = 500.f;
        CubeBuilder->Build(GetWorld(), BrushComponent->Brush);
    }
    
    // Atualiza a geometria
    BrushComponent->BuildSimpleBrushCollision();
    BrushComponent->UpdateBounds();
}