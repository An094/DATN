#include"utilities.h" // first
#include "Config.h"

void Init(Window*& window)
{
	window = new Window(width, height, nameWindow);
}


int main()
{
	Window* window = NULL;
	Init(window);
	window->Run();
}