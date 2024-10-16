#pragma once
#include <Object/Actor.h>

class BackgroundWindow : public AActor
{
public:
	void BeginPlay() override;
	void Tick() override;

private:
	class ConsoleEngine* engine = nullptr;
	class UConsoleWindow* window = nullptr;
};

