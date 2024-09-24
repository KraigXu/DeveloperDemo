// Fill out your copyright notice in the Description page of Project Settings.


#include "HexCell.h"

// Sets default values
AHexCell::AHexCell()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHexCell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHexCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexCell::SetTextContent_Implementation(const FString& InContent)
{
}


