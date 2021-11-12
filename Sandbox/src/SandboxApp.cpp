#include"utilities.h" // first
#include "Config.h"
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		std::cout << "Key: " << key << std::endl;
	}
}

void Init(Window*& window)
{
	window = new Window(width, height, nameWindow);
	glfwSetKeyCallback(window->getWindow(), KeyCallback);
}


int main()
{
	Window* window = NULL;
	Init(window);
	window->Run();
}