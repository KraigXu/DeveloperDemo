// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexGrid.generated.h"

class AHexCell;
class AHexMesh;

UCLASS()
class HEXMAP_API AHexGrid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHexGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void CreateCell(int32 Y,int32 X,int32 I);

	UFUNCTION(BlueprintCallable,Category="HexMap", meta = (DisplayName = "Init"))
	void V2_Init();

	void Init(TArray<AHexCell*> InHexCells);

	UFUNCTION(BlueprintCallable)
	void ColorCell(FVector InPosition,FColor InColor);
	


public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 Width=6;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 Height=6;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<AHexCell> HexCellObject;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	TArray<AHexCell*> HexCells;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TObjectPtr<AHexMesh> HexMesh;


	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="HexMap|Edit")
	FLinearColor TouchedColor=FColor::Red;
	
	
};
