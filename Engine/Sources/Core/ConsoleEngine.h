#pragma once
#include "Object/ActorVector.h"

class ConsoleEngine
{
public:
	static void Start();

	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	template<typename ActorType>
	ActorType* SpawnActor()
	{
		ActorType* NewActor = new ActorType();
		AllActorVector.push_back(NewActor);
		// 비긴플레이도 여기서 실행시켜준다.
		NewActor->BeginPlay();
		return NewActor;
	}

	static void ApplicationEnd()
	{
		// 일반 맴버변수를 static 함수 내부에서 사용하고 싶다면
		// static 변수를 기반으로 사용하면 된다.
		MainEngine->EngineActive = false;
	}

private:
	// 생성자를 막았어.
	ConsoleEngine();

	static ConsoleEngine* MainEngine;

	class UConsoleWindow* Window;
	bool EngineActive = true;

	ActorVector AllActorVector;

	void BeginPlay(); // 움직인다.
	void Tick(); // 움직인다.
	void Render(); // 그린다.

	void End();
};

