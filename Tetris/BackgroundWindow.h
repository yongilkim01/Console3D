#pragma once
#include <Object/Actor.h>

class BackgroundWindow : public AActor
{
public:
	static BackgroundWindow* BackWindow;

	void BeginPlay() override;
	void Tick() override;

	bool IsLineFull(int _Y);
	void SetLinePixel(int _Y, char _PiexelValue);
private:
	class ConsoleEngine* Engine = nullptr;
	class UConsoleWindow* Window = nullptr;

	char InitPixel = '.';
};