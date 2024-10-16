#include "BackgroundWindow.h"
#include <Object/Component/Renderer.h>
#include <Core/ConsoleEngine.h>
#include <Platform/Window.h>
#include <conio.h>

void BackgroundWindow::BeginPlay()
{
	Super::BeginPlay();

	engine = &ConsoleEngine::GetEngine();
	window = engine->GetWindow();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ window->GetWindowSizeX(), window->GetWindowSizeY() }, '.');
}

void BackgroundWindow::Tick()
{
	Super::Tick();
}