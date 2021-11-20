#include"GameObject/Window.h" // first
#include "Config.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameStates/GSIntro.h"
//class GSIntro;
void Init(Window*& window)
{
	GameStateMachine::GetInstance()->AddState(std::make_shared<GSIntro>());
	window = new Window(widthScreen, heightScreen, nameWindow);
}


int main()
{
	Window* window = NULL;
	Init(window);
	window->Run();
	return 0;
}