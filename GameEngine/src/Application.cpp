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

namespace EngineCore
{

	std::shared_ptr<Application> Application::s_Instance = nullptr;
	Application::Application()
	{
		m_CurrentTime = 0.0f;
		m_FpsCount = 0;
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
		Utils::Log::Init();
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
		if (m_CurrentTime < 1.0f)
		{
			m_CurrentTime += deltaTime;
			m_FpsCount++;
		}
		else
		{
			m_CurrentTime = 1.0f - m_CurrentTime;
			ENGINE_TRACE("FPS: {}", m_FpsCount);
			m_FpsCount = 0;
		}
		
		GameStateMachine::GetInstance()->GetCurrentState()->Update(deltaTime);
	}

	void Application::Draw()
	{
		GameStateMachine::GetInstance()->GetCurrentState()->Draw();
	}

	void Application::HandleKeyEvent(int key, bool isPressed)
	{
		GameStateMachine::GetInstance()->GetCurrentState()->HandleKeyEvents(key, isPressed);
	}

	void Application::HandleTouchEvent(double xpos, double ypos, bool isPressed)
	{
		GameStateMachine::GetInstance()->GetCurrentState()->HandleTouchEvents(static_cast<int>(xpos), static_cast<int>(ypos), isPressed);
	}
}