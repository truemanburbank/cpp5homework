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

	// Count��ŭ ��ǥ ���� �̵�
	for (int i = 0; i < STEP_COUNT; i++)
		Move();

	// �� �̵��� �Ÿ��� �̺�Ʈ �߻� �� ���
	UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f \t Total Event Count: %d"), totDist, evCnt);
}

// Called every frame
void AGameLogger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ������ ��ǥ�� ��ȯ�Ѵ�.
void AGameLogger::Move()
{
	// ���� �̺�Ʈ
	CreateEvent();

	int32_t nx = position.X + Step();
	int32_t ny = position.Y + Step();

	FVector2D curPos = position;
	FVector2D nextPos = FVector2D(nx, ny);

	// Distance, Position
	float curDist = Distance(nextPos, curPos);
	position = nextPos;

	// �Ÿ�, ��ǥ ���
	UE_LOG(LogTemp, Warning, TEXT("Distance: %f \t Cur position: (%d, %d)"), curDist, nx, ny);
	// ����
	UE_LOG(LogTemp, Warning, TEXT("----------------------------------------"), curDist, nx, ny);
}


// 0, 1�� �������� ��ȯ�Ѵ�.
// 50 �ۼ�Ʈ�� Ȯ���� �̺�Ʈ ȣ��
int32_t AGameLogger::Step()
{
	int32_t step = FMath::RandRange(MIN_STEP, MAX_STEP);

	return step;
}

float AGameLogger::Distance(FVector2D first, FVector2D second)
{
	float xDist = second.X - first.X;
	float yDist = second.Y - first.Y;

	// dist���ϰ� total dist�� ���� dist ���ϱ� 
	float dist = FMath::Sqrt(xDist * xDist + yDist * yDist);
	totDist += dist;

	return dist;
}

void AGameLogger::CreateEvent()
{
	int32_t flag = FMath::RandRange(0, 1);

	// �̺�Ʈ �߻�  
	if (flag == 1)
	{
		// �̺�Ʈ ���
		UE_LOG(LogTemp, Display, TEXT("Event!!!!!!!!!!!!!!"))
		evCnt++;
	}
}

