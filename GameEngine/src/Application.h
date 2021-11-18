#pragma once
#include<iostream>
#include <glad/glad.h>
class VAO;
class VBO;
class EBO;
class Texture;
class Model;
class Shader;
class Sprite2D;
class SpriteAnimation2D;
class Button;

class Application
{
private:
	//Window* m_window;
	static std::shared_ptr<Application> s_Instance;
	
	std::shared_ptr<Texture> m_Texture;
	std::shared_ptr<Model> m_Model;
	std::shared_ptr<Shader> m_Shader;

	std::shared_ptr<Sprite2D> m_sprite2d;
	std::shared_ptr<SpriteAnimation2D> m_spriteAnim;

	std::shared_ptr<Button> m_button;

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


