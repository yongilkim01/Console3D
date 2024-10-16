#include "BackgroundWindow.h"
#include <Object/Component/Renderer.h>
#include <Core/ConsoleEngine.h>
#include <Platform/Window.h>
#include <conio.h>

BackgroundWindow* BackgroundWindow::BackWindow = nullptr;

void BackgroundWindow::BeginPlay()
{
	BackWindow = this;
	Super::BeginPlay();

	Engine = &ConsoleEngine::GetEngine();
	Window = Engine->GetWindow();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ Window->GetWindowSizeX(), Window->GetWindowSizeY() }, InitPixel);
}

void BackgroundWindow::Tick()
{
	Super::Tick();

	for (int Y = Window->GetWindowSizeY() - 1; Y >= 0; Y--)
	{
		if (IsLineFull(Y))
		{
			SetLinePixel(Y, InitPixel);
		}
	}
}

bool BackgroundWindow::IsLineFull(int _Y)
{
	if (_Y == 9)
	{
		int a = 10;
	}
	for (int X = 0; X < Window->GetWindowSizeX(); X++)
	{
		if (GetImageRenderer()->RenderImage.GetPixel(X, _Y) == InitPixel)
		{
			return false;
		}
	}

	return true;
}

void BackgroundWindow::SetLinePixel(int _Y, char _PiexelValue)
{
	for (int X = 0; X < Window->GetWindowSizeX(); X++)
	{
		GetImageRenderer()->RenderImage.SetPixel({ X, _Y }, InitPixel);
	}
}
