#include "Application.h"
#include "shaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Model.h"
#include "Sprite2D.h"
#include "SpriteAnimation2D.h"
#include "ResourceManager.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameStateManager/GameStateBase.h"
#include "Button.h"
#include "Text.h"

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



	

	if (!GameStateMachine::GetInstance()->HasState())
	{
		GameStateMachine::GetInstance()->ChangeState(0);//Push state 0
	}	
	GameStateMachine::GetInstance()->GetCurrentState()->Init();
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
	GameStateMachine::GetInstance()->GetCurrentState()->Update(deltaTime);
}

void Application::Draw()
{
	GameStateMachine::GetInstance()->GetCurrentState()->Draw();
}

void Application::HandleKeyEvent(int key, bool isPressed)
{
	//std::cout << "Key: " << key << " isPressed: " << isPressed << std::endl;
}

void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{
	GameStateMachine::GetInstance()->GetCurrentState()->HandleTouchEvents(xpos, ypos, isPressed);
}