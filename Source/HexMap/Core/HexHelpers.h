// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexCell.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HexHelpers.generated.h"

/**
 * 
 */
UCLASS()
class HEXMAP_API UHexHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="HexMap")
	static FHexCoordinates HexCoordinatesFromPosition(FVector InPosition);
};
