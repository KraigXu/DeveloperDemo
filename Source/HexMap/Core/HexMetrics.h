// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class HEXMAP_API HexMetrics
{
public:
	HexMetrics();
	~HexMetrics();

	static void Initialize();

	inline static float OuterRadius=10.0f;

	inline static float InnerRadius;

	inline static TArray<FVector> Corners;
	
};

