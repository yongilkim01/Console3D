#pragma once
#include <vector>

class ConsoleEngine
{
public:
	static void Start(class UserInit* _Init);

	// static void Start(void(*Ptr)(ConsoleEngine* _Engine));

	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	class UConsoleWindow* GetWindow()
	{
		return Window;
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

	// ���漱�� �����൵ �ȴ�.
	std::vector<class AActor*> AllActorVector;

	void BeginPlay(); // �����δ�.
	void Tick(); // �����δ�.
	void Render(); // �׸���.

	void End();
};

// �������̽��� �����Ͽ뵵 ������ �����ؾ� �Ѵ�.
class UserInit
{
public:
	// ������ �ִ� ����� �̰� ���� ���ݽ��ϴ�.
	// 
	virtual void UserBeginPlay(ConsoleEngine* _MainEngine) = 0;
};

