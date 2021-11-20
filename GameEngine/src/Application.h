#pragma once
#include<iostream>
#include <glad/glad.h>

class Sprite2D;
class SpriteAnimation2D;
class Button;

class Application
{
private:
	static std::shared_ptr<Application> s_Instance;

	float m_currentTime;
	int m_fpsCount;
public:
	static std::shared_ptr<Application> GetInstance()
	{
		if (s_Instance == nullptr)
			s_Instance = std::make_shared<Application>();
		return s_Instance;
	}
	Application();
	~Application();

	void Init();
	void Update(GLfloat deltaTime);
	void Draw();
	void HandleKeyEvent(int key, bool isPressed);
	void HandleTouchEvent(double xpos, double ypos, bool isPressed);
	void Exit();
};


