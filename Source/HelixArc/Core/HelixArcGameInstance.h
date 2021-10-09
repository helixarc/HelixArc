// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HelixArcGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HELIXARC_API UHelixArcGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class UItemsDatabase* ItemDatabase;
};
