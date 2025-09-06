// Função para converter um actor BSP em Static Mesh
void ConvertBSPToStaticMesh(ABrush* BrushActor, UWorld* World)
{
    if (!BrushActor || !World) return;
    
    // Configurações para a conversão
    FStaticMeshExportOptions Options;
    Options.bSelectedOnly = true;
    
    // Cria um nome único para o novo Static Mesh
    FString MeshName = TEXT("ConvertedMesh_") + BrushActor->GetName();
    FString PackageName = TEXT("/Game/ConvertedMeshes/") + MeshName;
    
    // Cria o pacote para o novo asset
    UPackage* Package = CreatePackage(*PackageName);
    
    // Realiza a conversão
    UStaticMesh* NewStaticMesh = FBrushExport::ExportBrushAsStaticMesh(
        BrushActor, 
        Package, 
        *MeshName, 
        Options
    );
    
    if (NewStaticMesh)
    {
        // Salva o novo asset
        NewStaticMesh->MarkPackageDirty();
        FAssetRegistryModule::AssetCreated(NewStaticMesh);
        
        // Aqui você pode substituir o BSP pelo novo Static Mesh no nível
        UE_LOG(LogTemp, Log, TEXT("BSP convertido para Static Mesh com sucesso: %s"), *NewStaticMesh->GetName());
    }
}