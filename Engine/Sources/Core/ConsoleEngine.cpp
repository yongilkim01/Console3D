// 상속헤더
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

	// 콜백
	// Ptr(&Engine);

	while (true == Engine.EngineActive)
	{
		Engine.Tick();
		Engine.Render();
		Engine.Release(); // 한프레임의 모든 과정이 끝났을때
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

	// 대리객체 방법이 있습니다.

	// 나중에 배우겠습니다.
	// 함수포인터로 하는법
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

		// 예상안됨
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
	// tick도 끝나고
	// 랜더도 끝나고
	for (size_t i = 0; i < AllActorVector.size(); i++)
	{
		if (false == AllActorVector[i]->IsDestory())
		{
			continue;
		}

		// 벡터는 구멍이 뚫립니다.
		delete AllActorVector[i];
		AllActorVector[i] = nullptr;
	}
}