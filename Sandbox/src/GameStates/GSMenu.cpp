#include "GSMenu.h"


extern GLint widthScreen;
extern GLint heightScreen;
extern GLint hightestLogo;
extern GLint lowestLogo;

void GSMenu::Init()
{
	//backgroud
	m_Background = std::make_shared<EngineCore::Sprite2D>("background.tga");
	m_Background->SetPosition(widthScreen / 2, heightScreen / 2);
	m_Background->SetSize(widthScreen, heightScreen);

	//logo
	m_Logo = std::make_shared<EngineCore::Sprite2D>("LogoGame.tga");
	m_Logo->SetPosition(widthScreen / 2, heightScreen * 3 / 4);
	m_Logo->SetSize(400, 200);
	logoGoDown = true;
	speedLogo = 50.0f;

	//button play
	m_PlayButton = std::make_shared<EngineCore::Button>("Menu/button_play.tga");
	m_PlayButton->SetPosition(widthScreen / 2, heightScreen / 2 - 50);
	m_PlayButton->SetSize(300, 150);
	m_PlayButton->SetOnClick([]()
		{
			EngineCore::GameStateMachine::GetInstance()->ChangeState(2);//GSPlay
		});

	//button setting
	m_SettingButton = std::make_shared<EngineCore::Button>("Menu/button_setting.tga", "Texture", "Texture", EngineCore::ButtonType::CIRCLE);
	m_SettingButton->SetPosition(widthScreen - 50, 150);
	m_SettingButton->SetSize(50, 50);
	m_SettingButton->SetOnClick([]() {
			EngineCore::GameStateMachine::GetInstance()->ChangeState(3);//GSSetting
		});

	//button quit
	m_QuitButton = std::make_shared<EngineCore::Button>("Menu/button_exit.tga", "Texture", "Texture", EngineCore::ButtonType::CIRCLE);
	m_QuitButton->SetPosition(widthScreen - 50, 75);
	m_QuitButton->SetSize(50, 50);
	m_QuitButton->SetOnClick([]() {
			exit(0);
		});

	//Sound
	EngineCore::ResourceManager::GetInstance()->PlaySound(EngineCore::AUDIO_TYPE::MUSIC, "music_game.wav", true);
}

void GSMenu::Update(float deltaTime)
{
	float ypos = m_Logo->GetPosition().y;
	float xpos = m_Logo->GetPosition().x;
	if (logoGoDown && ypos > lowestLogo)
	{
		m_Logo->SetPosition(xpos, ypos - speedLogo * deltaTime);
	}
	else if(!logoGoDown && ypos < hightestLogo)
	{
		m_Logo->SetPosition(xpos, ypos + speedLogo * deltaTime);
	}
	else
	{
		logoGoDown = !logoGoDown;
	}
}

void GSMenu::Draw()
{
	m_Background->Draw();
	m_Logo->Draw();
	m_PlayButton->Draw();
	m_SettingButton->Draw();
	m_QuitButton->Draw();
}

void GSMenu::Pause()
{

}

void GSMenu::Exit()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	m_PlayButton->HandleTouchEvent(x, y, bIsPressed);
	m_SettingButton->HandleTouchEvent(x, y, bIsPressed);
	m_QuitButton->HandleTouchEvent(x, y, bIsPressed);
}