#include"GameObject/Window.h" // first
#include "Config.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameStates/GSIntro.h"
#include "GameStates/GSMenu.h"
//class GSIntro;
void Init(Window*& window)
{
	GameStateMachine::GetInstance()->AddState(std::make_shared<GSIntro>());
	GameStateMachine::GetInstance()->AddState(std::make_shared<GSMenu>());

	window = new Window(widthScreen, heightScreen, nameWindow);
}


int main()
{
	Window* window = NULL;
	Init(window);
	window->Run();
	return 0;
}