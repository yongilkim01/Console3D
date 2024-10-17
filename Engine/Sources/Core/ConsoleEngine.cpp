// ������
#include "ConsoleEngine.h"

// Platform
#include <Windows.h>

// User
#include "Platform/Window.h"
#include "Object/Actor.h"

ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

ConsoleEngine::ConsoleEngine()
{

}


// void ConsoleEngine::Start(void(*Ptr)(ConsoleEngine*))
void ConsoleEngine::Start(class UserInit* _Init)
{
	ConsoleEngine Engine;

	MainEngine = &Engine;

	Engine.BeginPlay();

	_Init->UserBeginPlay(&Engine);

	// �ݹ�
	// Ptr(&Engine);

	while (true == Engine.EngineActive)
	{
		Engine.Tick();
		Engine.Render();
		Engine.Release(); // ���������� ��� ������ ��������
		Sleep(250);
	}

	Engine.End();
}

void ConsoleEngine::End()
{
	if (nullptr != Window)
	{
		delete Window;
		Window = nullptr;
	}
}

void ConsoleEngine::BeginPlay()
{
	Window = new UConsoleWindow();
	Window->BeginPlay();

	// �븮��ü ����� �ֽ��ϴ�.

	// ���߿� ���ڽ��ϴ�.
	// �Լ������ͷ� �ϴ¹�
	Window->SetScreenSize({ 10, 10 });
}

void ConsoleEngine::Tick()
{
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		if (false == AllActorVector[i]->IsTickable())
		{
			continue;
		}

		AllActorVector[i]->Tick();

		// ����ȵ�
		//if (true == AllActorVector[i]->IsDestory())
		//{
		//	delete AllActorVector[i];
		//}
	}
}

void ConsoleEngine::Render()
{
	Window->Clear();

	ConsoleImage* BackBufferPtr = Window->GetBackBufferPtr();
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		if (false == AllActorVector[i]->IsTickable())
		{
			continue;
		}

		AllActorVector[i]->Render(BackBufferPtr);
	}

	Window->ScreenRender();
}

void ConsoleEngine::Release()
{
	// tick�� ������
	// ������ ������
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		if (false == AllActorVector[i]->IsDestory())
		{
			continue;
		}

		// ���ʹ� ������ �ո��ϴ�.
		delete AllActorVector[i];
		AllActorVector[i] = nullptr;
	}
}