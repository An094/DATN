#include"GameObject/Window.h" // first
#include "Config.h"

void Init(Window*& window)
{
	window = new Window(widthScreen, heightScreen, nameWindow);
}


int main()
{
	Window* window = NULL;
	Init(window);
	window->Run();
	return 0;
}