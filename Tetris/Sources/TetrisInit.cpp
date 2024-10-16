#include "TetrisInit.h"
#include <Core/ConsoleEngine.h>
#include <Platform/Window.h>
#include "Block.h"
#include "../BackgroundWindow.h"

void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	_MainEngine->GetWindow()->SetScreenSize({ 5, 13 });
	_MainEngine->SpawnActor<BackgroundWindow>();
}