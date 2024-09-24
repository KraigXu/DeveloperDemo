// Fill out your copyright notice in the Description page of Project Settings.


#include "HexMetrics.h"


HexMetrics::HexMetrics()
{
}

HexMetrics::~HexMetrics()
{
}

void HexMetrics::Initialize()
{
	InnerRadius=OuterRadius*0.866025404f;

	Corners = {
		FVector(OuterRadius,0.f,0.f),
		FVector(0.5f * OuterRadius,InnerRadius,0.f),
		FVector(-0.5f * OuterRadius,InnerRadius,0.f),
		FVector(-OuterRadius,0.f,0.f),
		FVector(-0.5f * OuterRadius,-InnerRadius,0.f),
		FVector(0.5f * OuterRadius,-InnerRadius,0.f),
		FVector(OuterRadius,0.f,0.f)
	};
}
