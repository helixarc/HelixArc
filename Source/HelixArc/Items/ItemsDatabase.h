// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include <HelixArc/Items/ItemData.h>
#include "ItemsDatabase.generated.h"

/**
 * 
 */
UCLASS()
class HELIXARC_API UItemsDatabase : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Items")
		TMap<int, UItemData*> Items;
	
};
