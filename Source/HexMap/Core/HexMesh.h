// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "HexMesh.generated.h"

class AHexCell;

UCLASS()
class HEXMAP_API AHexMesh : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHexMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Triangulate(TArray<AHexCell*> InHexCell);
	void Triangulate(AHexCell* InHexCell);

	void AddTriangle(FVector V1,FVector V2,FVector V3);

	void AddTriangleColor(FLinearColor InColor);

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HexMap")
	TObjectPtr<UMaterialInterface> Material;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HexMap", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UProceduralMeshComponent> MeshComponent;
	
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FLinearColor> VertexColors;
	TArray<FVector2D> Uvs;

	
};
