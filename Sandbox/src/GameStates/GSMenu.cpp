#include "GSMenu.h"
#include "GameObject/Button.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameManager/ResourceManager.h"
void GSMenu::Init()
{
	m_buttonBack = std::make_shared<Button>("Texture", "Texture", "back_play.tga", ButtonType::CIRCLE);
	m_buttonBack->SetPosition(400, 400);
	m_buttonBack->SetSize(200, 200);
	m_buttonBack->SetOnClick([]()
		{
			GameStateMachine::GetInstance()->PopState();
			ResourceManager::GetInstance()->SetVolume(AUDIO_TYPE::MUSIC, 0.1f);
			ResourceManager::GetInstance()->PlaySound(AUDIO_TYPE::SOUND, "coin.mp3");
		});
}

void GSMenu::Update(float deltaTime)
{

}

void GSMenu::Draw()
{
	m_buttonBack->Draw();
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
	m_buttonBack->HandleTouchEvent(x, y, bIsPressed);
}