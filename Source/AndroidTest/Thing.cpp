// Fill out your copyright notice in the Description page of Project Settings.


#include "Thing.h"
#include <Engine/Engine.h>

// Sets default values
AThing::AThing()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TheRoot"));
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

void AThing::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UE_LOG(LogTemp, Display, TEXT("AThing::PreInitializeComponents()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AThing::PreInitializeComponents()"));
	}
	if (Mesh)
	{
		UStaticMeshComponent* Component = NewObject<UStaticMeshComponent>(this);
		Component->SetupAttachment(RootComponent);
		Component->SetStaticMesh(Mesh);
		RegisterAllComponents();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Mesh not specified"));
	}
}

