// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexCell.generated.h"

USTRUCT(BlueprintType)
struct FHexCoordinates
{
	GENERATED_BODY()

	
	FHexCoordinates()
	{
		X=0;
		Y=0;
	};

	FHexCoordinates(int32 InX,int32 InY)
	{
		X=InX;
		Y=InY;
	}
	
	/**
	 * temp:对应Unity Z
	 */
	UPROPERTY(BlueprintReadOnly)
	int32 X=0;

	/**
	 * temp:对应Unity X
	 */
	UPROPERTY(BlueprintReadOnly)
	int32 Y=0;
	
	/**
	 * temp:对应Unity Y
	 * @return 
	 */
	int32 Z(){
		return  -Y-X;
	}
	
	FString ToString()
	{
		return FString::Printf(TEXT("%i;%i;%i"),X,Y,Z());
	}
	
	static FHexCoordinates FromOffsetCoordinates(int32 InX,int32 InY)
	{
		return FHexCoordinates(InX,InY-InX/2);
	}
};


UCLASS()
class HEXMAP_API AHexCell : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHexCell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void SetTextContent(const FString& InContent);
	
public:
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere)
	FHexCoordinates Coordinates;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	FLinearColor Color=FColor::White;

	
};
