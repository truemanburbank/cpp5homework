// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLogger.h"

// Sets default values
AGameLogger::AGameLogger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameLogger::BeginPlay()
{
	Super::BeginPlay();

	// Count만큼 좌표 랜덤 이동
	for (int i = 0; i < STEP_COUNT; i++)
		Move();

	// 총 이동한 거리와 이벤트 발생 수 출력
	UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f \t Total Event Count: %d"), totDist, evCnt);
}

// Called every frame
void AGameLogger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 랜덤한 좌표를 반환한다.
void AGameLogger::Move()
{
	// 랜덤 이벤트
	CreateEvent();

	int32_t nx = position.X + Step();
	int32_t ny = position.Y + Step();

	FVector2D curPos = position;
	FVector2D nextPos = FVector2D(nx, ny);

	// Distance, Position
	float curDist = Distance(nextPos, curPos);
	position = nextPos;

	// 거리, 좌표 출력
	UE_LOG(LogTemp, Warning, TEXT("Distance: %f \t Cur position: (%d, %d)"), curDist, nx, ny);
	// 개행
	UE_LOG(LogTemp, Warning, TEXT("----------------------------------------"), curDist, nx, ny);
}


// 0, 1을 랜덤으로 반환한다.
// 50 퍼센트의 확률로 이벤트 호출
int32_t AGameLogger::Step()
{
	int32_t step = FMath::RandRange(MIN_STEP, MAX_STEP);

	return step;
}

float AGameLogger::Distance(FVector2D first, FVector2D second)
{
	float xDist = second.X - first.X;
	float yDist = second.Y - first.Y;

	// dist구하고 total dist에 현재 dist 더하기 
	float dist = FMath::Sqrt(xDist * xDist + yDist * yDist);
	totDist += dist;

	return dist;
}

void AGameLogger::CreateEvent()
{
	int32_t flag = FMath::RandRange(0, 1);

	// 이벤트 발생  
	if (flag == 1)
	{
		// 이벤트 출력
		UE_LOG(LogTemp, Display, TEXT("Event!!!!!!!!!!!!!!"))
		evCnt++;
	}
}

