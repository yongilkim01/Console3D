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
		// ����÷��̵� ���⼭ ��������ش�.
		NewActor->BeginPlay();
		return NewActor;
	}

	static void ApplicationEnd()
	{
		// �Ϲ� �ɹ������� static �Լ� ���ο��� ����ϰ� �ʹٸ�
		// static ������ ������� ����ϸ� �ȴ�.
		MainEngine->EngineActive = false;
	}

private:
	// �����ڸ� ���Ҿ�.
	ConsoleEngine();

	static ConsoleEngine* MainEngine;

	class UConsoleWindow* Window;
	bool EngineActive = true;

	ActorVector AllActorVector;

	void BeginPlay(); // �����δ�.
	void Tick(); // �����δ�.
	void Render(); // �׸���.

	void End();
};

