// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGrid.h"

#include "HexCell.h"
#include "HexHelpers.h"
#include "HexMesh.h"
#include "HexMetrics.h"


// Sets default values
AHexGrid::AHexGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HexMetrics::Initialize();
}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	HexCells.SetNum(Width*Height);

	for (int x=0,i=0;x<Height;x++)
	{
		for (int y=0;y<Width;y++)
		{
			CreateCell(y,x,i++);
		}
	}
}

// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexGrid::CreateCell(int32 Y, int32 X, int32 I)
{
	FVector LocalPos=FVector(
		X*(HexMetrics::OuterRadius*1.5f),
		(Y+X*0.5f-X/2)*(HexMetrics::InnerRadius*2.f), 
		0);

	AHexCell* LocalItem=GetWorld()->SpawnActor<AHexCell>(HexCellObject,FTransform::Identity);
	LocalItem->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
	LocalItem->SetActorLocation(LocalPos);
	LocalItem->Coordinates=FHexCoordinates::FromOffsetCoordinates(X,Y);
	LocalItem->SetTextContent(LocalItem->Coordinates.ToString());
	HexCells[I]=LocalItem;
}

void AHexGrid::V2_Init()
{
	Init(HexCells);
}

void AHexGrid::Init(TArray<AHexCell*> InHexCells)
{
	HexMesh->Triangulate(InHexCells);
}

void AHexGrid::ColorCell(FVector InPosition,FColor InColor)
{
	FHexCoordinates LocalHexCoordinates= UHexHelpers::HexCoordinatesFromPosition(InPosition);
	const int32 Index=LocalHexCoordinates.Y+LocalHexCoordinates.X*Width+LocalHexCoordinates.X/2;
	AHexCell* LocalHexCell= HexCells[Index];
	LocalHexCell->Color=InColor;
	HexMesh->Triangulate(HexCells);

}

