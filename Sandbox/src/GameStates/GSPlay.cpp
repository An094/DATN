#include "GSPlay.h"
#include "Application.h"
#include "GameObject/OrthographicCamera.h"

extern GLint widthScreen;
extern GLint heightScreen;
GSPlay::GSPlay()
{

}

GSPlay::~GSPlay()
{

}

void GSPlay::Init()
{
	m_MapController = std::make_shared<MapController>(2);
	m_Background = std::make_shared<EngineCore::Sprite2D>("Tile/-1.tga");
	m_Background->SetSize(widthScreen * 3, heightScreen * 3);
	m_Background->SetPosition(widthScreen / 2, heightScreen / 2);

	//m_text = std::make_shared<EngineCore::Text>("arial.ttf", "Hello", 100, glm::vec3(1.0f, 0.0f, 1.0f));
	//m_text->SetPosition(200, 150);
}

void GSPlay::Update(float deltaTime)
{
	m_MapController->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_Background->Draw();
	m_MapController->Draw();
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	m_MapController->HandleKeyEvent(key, bIsPressed);
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	m_MapController->HandleTouchEvents(x, y, bIsPressed);
}

void GSPlay::Pause()
{

}

void GSPlay::Exit()
{

}