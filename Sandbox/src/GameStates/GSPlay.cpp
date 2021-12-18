#include "GSPlay.h"


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
	m_sprite2d = std::make_shared<EngineCore::Sprite2D>("bg_play.tga");
	m_sprite2d->SetPosition(widthScreen/2, heightScreen/2);
	m_sprite2d->SetSize(widthScreen, heightScreen);

	m_button = std::make_shared<EngineCore::Button>("back_play.tga", "Texture", "Texture", EngineCore::ButtonType::CIRCLE);
	m_button->SetPosition(widthScreen/2, heightScreen *2/3);
	m_button->SetSize(200, 200);
	m_button->SetOnClick([]()
		{
			EngineCore::GameStateMachine::GetInstance()->PopState();
		});
	m_Player = std::make_shared<Player>();
	m_Player->Init();

	m_text = std::make_shared<EngineCore::Text>("arial.ttf", "Hello", 100, glm::vec3(1.0f, 0.0f, 1.0f));
	m_text->SetPosition(200, 150);
}

void GSPlay::Update(float deltaTime)
{
	m_Player->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_sprite2d->Draw();
	m_Player->Draw();
	m_button->Draw();
	m_text->Draw();
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	m_Player->HandleKeyEvents(key, bIsPressed);
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	m_button->HandleTouchEvent(x, y, bIsPressed);
}

void GSPlay::Pause()
{

}

void GSPlay::Exit()
{

}