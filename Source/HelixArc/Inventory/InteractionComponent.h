// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractDelegate, class AHelixArcCharacter*, Player);

USTRUCT(BlueprintType)
struct FInteractionData
{
	GENERATED_BODY();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AActor* Actor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FText InteractionText;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HELIXARC_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction")
		FText InteractionText = FText::FromString("Default Interaction");

	UPROPERTY(BlueprintAssignable)
		FInteractDelegate OnInteract;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void Interact(class AHelixArcCharacter* Player);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
