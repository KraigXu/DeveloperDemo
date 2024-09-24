// Fill out your copyright notice in the Description page of Project Settings.

#include "HexMesh.h"

#include "HexCell.h"
#include "HexMetrics.h"

// Sets default values
AHexMesh::AHexMesh()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
}

// Called when the game starts or when spawned
void AHexMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHexMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AHexMesh::Triangulate(TArray<AHexCell*> InHexCell)
{
	MeshComponent->ClearAllMeshSections();
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	Uvs.Empty();
	VertexColors.Empty();
	Tangents.Empty();

	for (auto Item :InHexCell)
	{
		Triangulate(Item);
	}
	MeshComponent->SetMaterial(0,Material);
	MeshComponent->CreateMeshSection_LinearColor(0,Vertices,Triangles,Normals,Uvs,VertexColors,Tangents,true);

}

void AHexMesh::Triangulate(AHexCell* InHexCell)
{
	FVector LocalCenter=InHexCell->GetActorLocation();

	for(int i=0;i<6;i++)
	{
		AddTriangle(
			LocalCenter,
			LocalCenter+HexMetrics::Corners[i],
			LocalCenter+HexMetrics::Corners[i+1]
		);

		AddTriangleColor(InHexCell->Color);
	}
}

void AHexMesh::AddTriangle(FVector V1, FVector V2, FVector V3)
{
	int32 LocalVertexIndex=Vertices.Num();
	Vertices.Add(V1);
	Vertices.Add(V2);
	Vertices.Add(V3);
	
	Triangles.Add(LocalVertexIndex);
	Triangles.Add(LocalVertexIndex+1);
	Triangles.Add(LocalVertexIndex+2);
}

void AHexMesh::AddTriangleColor(FLinearColor InColor)
{
	VertexColors.Add(InColor);
	VertexColors.Add(InColor);
	VertexColors.Add(InColor);

	Tangents.Add(FProcMeshTangent(0,1,0));
	Tangents.Add(FProcMeshTangent(0,1,0));
	Tangents.Add(FProcMeshTangent(0,1,0));

	Normals.Add(FVector(1,0,0));
	Normals.Add(FVector(1,0,0));
	Normals.Add(FVector(1,0,0));

	Uvs.Add(FVector2D(0,0));
	Uvs.Add(FVector2D(10,0));
	Uvs.Add(FVector2D(0,10));
	
}

