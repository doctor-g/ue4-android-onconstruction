// Fill out your copyright notice in the Description page of Project Settings.


#include "Thing.h"
#include <Engine/Engine.h>

// Sets default values
AThing::AThing()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AThing::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("AThing::BeginPlay()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AThing::BeginPlay()"));
	}
}

void AThing::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
	UE_LOG(LogTemp, Display, TEXT("AThing::OnConstruction()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AThing::OnConstruction()"));
	}
}

