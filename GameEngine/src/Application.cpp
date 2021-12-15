#include "Application.h"
#include "GameObject/shaderClass.h"
#include "GameObject/VBO.h"
#include "GameObject/VAO.h"
#include "GameObject/EBO.h"
#include "GameObject/Model.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/SpriteAnimation2D.h"
#include "GameManager/ResourceManager.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameStateManager/GameStateBase.h"
#include "GameObject/Button.h"
#include "GameObject/Text.h"
#include "Utils/Log.h"
#include "GameObject/OrthographicCamera.h"
std::shared_ptr<Application> Application::s_Instance = nullptr;
Application::Application()
{
	m_currentTime = 0.0f;
	m_fpsCount = 0;
}

Application::~Application()
{

}

std::shared_ptr<OrthographicCamera> Application::GetCamera()
{
	return m_Camera;
}

void Application::Init()
{
	Log::Init();
	ENGINE_INFO("OpenGL information");
	ENGINE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
	ENGINE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
	ENGINE_INFO("Version: {0}", glGetString(GL_VERSION));
	////Initialize data
	ResourceManager::GetInstance()->Init();
	m_Camera = std::make_shared<OrthographicCamera>(-1.0f, 1.0f, -1.0f, 1.0f);
	if (!GameStateMachine::GetInstance()->HasState())
	{
		GameStateMachine::GetInstance()->ChangeState(0);//Push state 0
	}	
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
		ENGINE_TRACE("FPS: {}", m_fpsCount);
		m_fpsCount = 0;
	}
	if (m_Key == GLFW_KEY_A)
	{
		m_Camera->MoveLeft(deltaTime);
	}
	else if (m_Key == GLFW_KEY_D)
	{
		m_Camera->MoveRight(deltaTime);
	}
	else if (m_Key == GLFW_KEY_W)
	{
		m_Camera->MoveUp(deltaTime);
	}
	else if (m_Key == GLFW_KEY_S)
	{
		m_Camera->MoveDown(deltaTime);
	}
	m_Key = 0;
	GameStateMachine::GetInstance()->GetCurrentState()->Update(deltaTime);
}

void Application::Draw()
{
	GameStateMachine::GetInstance()->GetCurrentState()->Draw();
}

void Application::HandleKeyEvent(int key, bool isPressed)
{
	GameStateMachine::GetInstance()->GetCurrentState()->HandleKeyEvents(key, isPressed);
	m_Key = key;
}

void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
{
	GameStateMachine::GetInstance()->GetCurrentState()->HandleTouchEvents(xpos, ypos, isPressed);
}