#pragma once
#include "utilities.h"
//#include "Config.h"
class Application
{
private:
	Window* m_window;
public:
	Application();
	~Application();
	void Init();
	void Update(GLfloat deltaTime);
	void Draw();
	void HandleKeyEvent(int key, bool isPressed);
	void Exit();
};

