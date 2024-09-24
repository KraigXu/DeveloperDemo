// Fill out your copyright notice in the Description page of Project Settings.


#include "HexHelpers.h"

#include "HexMetrics.h"

FHexCoordinates UHexHelpers::HexCoordinatesFromPosition(FVector InPosition)
{
	float Y=InPosition.Y/(HexMetrics::InnerRadius*2.f);
	float Z=-Y;

	float Offset=InPosition.X/(HexMetrics::OuterRadius*3.f);
	Y-=Offset;
	Z-=Offset;

	int32 IY=FMath::RoundToInt(Y);
	int32 IZ=FMath::RoundToInt(Z);
	int32 IX=FMath::RoundToInt(-Y -Z);
	
	if(IX+IY+IZ!=0)
	{
		float DY=FMath::Abs(Y-IY);
		float DZ=FMath::Abs(Z-IZ);
		float DX=FMath::Abs( -Y -Z -IX);
		
		if(DY>DZ && DY>DX)
		{
			IY=-IZ-IX;
		}else if(DX>DY)
		{
			IX=-IY-IZ;
		}
	}
	
	
	return FHexCoordinates(IX,IY); 
}
