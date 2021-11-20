#include "Application.h"
#include "shaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Model.h"
#include "Sprite2D.h"
#include "SpriteAnimation2D.h"
#include "ResourceManager.h"
#include "Button.h"

std::shared_ptr<Application> Application::s_Instance = nullptr;
Application::Application()
{
	m_currentTime = 0.0f;
	m_fpsCount = 0;
}

Application::~Application()
{

}

void Application::Init()
{
	////Initialize data
	ResourceManager::GetInstance()->Init();



	m_sprite2d = std::make_shared<Sprite2D>("Texture", "Texture", "bg_play.tga");
	m_sprite2d->SetPosition(400, 400);
	m_sprite2d->SetSize(800, 800);

	m_button = std::make_shared<Button>("Texture", "Texture", "Load.tga");
	m_button->SetPosition(400, 600);
	m_button->SetSize(400, 150);
	m_button->SetOnClick([]()
		{
			std::cout << "Button is clicked" << std::endl;
		});


	m_spriteAnim = std::make_shared<SpriteAnimation2D>("Texture", "Animation", "poo_down.tga", 6, 0.1f);
	m_spriteAnim->SetPosition(400, 400);
	m_spriteAnim->SetSize(100, 100);
}

void Application::Update(GLfloat deltaTime)
{
	if (m_currentTime < 1.0f)
	{
		m_currentTime += deltaTime;
		m_fpsCount++;
	}
	else
	{
		m_currentTime = 1.0f - m_currentTime;
		std::cout << "FPS: " << m_fpsCount << std::endl;
		m_fpsCount = 0;
	}
	m_spriteAnim->Update(deltaTime);
}

void Application::Draw()
{
	//m_sprite2d->Draw();
	m_sprite2d->Draw();
	m_spriteAnim->Draw();
	m_button->Draw();
}

void Application::HandleKeyEvent(int key, bool isPressed)
{
	//std::cout << "Key: " << key << " isPressed: " << isPressed << std::endl;
}

void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{
	m_button->HandleTouchEvent(xpos, ypos, isPressed);
}