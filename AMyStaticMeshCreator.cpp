//Fabio Leandro Lapuinka 06/09/2025
// No arquivo .cpp
#include "MyStaticMeshCreator.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AMyStaticMeshCreator::AMyStaticMeshCreator()
{
    PrimaryActorTick.bCanEverTick = false;
    
    // Cria o componente de Static Mesh
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;
    
    // Encontra e aplica um asset de mesh existente
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
    }
    
    // Encontra e aplica um material
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/StarterContent/Materials/M_Metal_Brushed_Nickel.M_Metal_Brushed_Nickel"));
    if (MaterialAsset.Succeeded())
    {
        StaticMeshComponent->SetMaterial(0, MaterialAsset.Object);
    }
    
    // Define propriedades físicas
    StaticMeshComponent->SetSimulatePhysics(false);
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
