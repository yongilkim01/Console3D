#pragma once
#include <../../BaseSystem/Sources/Math/Math.h>
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

	// 전방선언도 안해줘도 된다.
	// 포인터로 new 여러분들 알수 있나요? 
	// 최대한 가독성 위주로한 코드를 칠겁니다.
	std::vector<class AActor*> AllActorVector;
	// std::list<class AActor*> AllActorVector;

	void BeginPlay(); // 움직인다.
	void Tick(); // 움직인다.
	void Release(); // 정리할 오브젝트들을 정리하는.

	void Render(); // 그린다.

	void End();
};

// 인터페이스를 제공하용도 유저가 공부해야 한다.
class UserInit
{
public:
	// 경험이 있는 사람은 이걸 보고 깨닫습니다.
	// 
	virtual void UserBeginPlay(ConsoleEngine* _MainEngine) = 0;
};

