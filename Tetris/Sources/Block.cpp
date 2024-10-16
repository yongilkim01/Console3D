#include "Block.h"
#include <Object/Component/Renderer.h>
#include <Core/ConsoleEngine.h>
#include <Platform/Window.h>
#include <conio.h>


void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	engine = &ConsoleEngine::GetEngine();
}

void Block::Tick()
{
	Super::Tick();

	AddActorLocation(FIntPoint::DOWN);

	if (GetActorLocation().Y == ConsoleEngine::GetEngine().GetWindow()->GetWindowSizeY() - 1) // ����� ��ġ�� �ٴڿ� ����� �� �˻�
	{
		// TODO: �����쿡 �״� �ڵ� �߰�.
		GetImageRenderer()->Active = false;
		ConsoleEngine::GetEngine().GetWindow()->GetBackBufferPtr()->ChangePixelPos.push_back(GetActorLocation());
	}
}