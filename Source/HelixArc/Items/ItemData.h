// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class HELIXARC_API UItemData : public UDataAsset
{
	GENERATED_BODY()
	
public:

	//ID of the item.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int ItemID;

	//Name of the Item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		FText ItemName;

	//How much does this item weight per unit?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float WeightPerUnit;

	//Can this item be stacked?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool bStackable;

	//How many instances of this item can exist in a stack?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int MaxStackSize;

	//Can this item be consumed?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		bool bConsumable;

	//How much does this item replenish when consumed?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int ReplenishAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UBlueprint* ItemBlueprint;
};
