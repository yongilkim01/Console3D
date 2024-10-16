#include "Block.h"
#include <Object/Component/Renderer.h>
#include <Core/ConsoleEngine.h>
#include <Platform/Window.h>
#include <conio.h>
#include "../BackgroundWindow.h"


void Block::BeginPlay()
{
	Super::BeginPlay();
	Renderer* Render = CreateDefaultSubObject();

	Render->RenderImage.Create({ 1, 1 }, 'O');
	SetActorLocation(SpawnPos);

	Engine = &ConsoleEngine::GetEngine();
}

void Block::Tick()
{
	Super::Tick();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			break;

		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			break;
		}
	}

	if (BackgroundWindow::BackWindow->GetImageRenderer()->RenderImage.GetImageSize().Y - 1 > GetActorLocation().Y)
	{
		if (BackgroundWindow::BackWindow->GetImageRenderer()->RenderImage.GetPixel(GetActorLocation().X, GetActorLocation().Y + 1) == 'O')
		{
			BackgroundWindow::BackWindow->GetImageRenderer()->RenderImage.SetPixel(GetActorLocation(), 'O');
			SetActorLocation(SpawnPos);
		}
		AddActorLocation(FIntPoint::DOWN);
	}
	else if (GetActorLocation().Y == BackgroundWindow::BackWindow->GetImageRenderer()->RenderImage.GetImageSize().Y - 1) // 블록의 위치가 바닥에 닿았을 때 검사
	{
		// TODO: 윈도우에 쌓는 코드 추가.
		BackgroundWindow::BackWindow->GetImageRenderer()->RenderImage.SetPixel(GetActorLocation(), 'O');
		SetActorLocation(SpawnPos);
	}
}