#include "GameEngine.h"
#include "Config.h"
#include "GameStates/GSIntro.h"
#include "GameStates/GSMenu.h"

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
	CLIENT_INFO("Screen width: {0}, Screen height: {1}", widthScreen, heightScreen);
	window->Run();
	return 0;
}