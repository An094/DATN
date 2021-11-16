#pragma once
#include<iostream>
#include <glad/glad.h>
class VAO;
class VBO;
class EBO;
class Texture;
class Shader;
class Application 
{
private:
	//Window* m_window;
	static std::shared_ptr<Application> s_Instance;
	
	std::shared_ptr<VAO> m_VAO;
	std::shared_ptr<Texture> m_Texture;
	std::shared_ptr<Shader> m_Shader;

	bool m_isPressed;
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


