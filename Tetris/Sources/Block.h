#pragma once
#include <Object/Actor.h>
#include <../../BaseSystem/Sources/Math/Math.h>

class Block : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

private:
	class ConsoleEngine* Engine = nullptr;
	FIntPoint SpawnPos = { 1, 0 };
};

