// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameLogger.generated.h"

UCLASS()
class HELLO_API AGameLogger : public AActor
{
	GENERATED_BODY()
private:
	FVector2D position;
	int32 evCnt;
	float totDist;

public:
	const int32_t MIN_STEP = 0;
	const int32_t MAX_STEP = 1;
	const int32_t STEP_COUNT = 10;
	
public:	
	// Sets default values for this actor's properties
	AGameLogger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	void Move();
	int32_t Step();

	float Distance(FVector2D first, FVector2D second);
	void CreateEvent();
};
