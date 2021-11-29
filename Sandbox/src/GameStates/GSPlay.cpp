#include "GSPlay.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/SpriteAnimation2D.h"
#include "GameObject/Button.h"
#include "GameObject/Text.h"
#include "GameManager/ResourceManager.h"

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
	m_sprite2d = std::make_shared<Sprite2D>("Texture", "Texture", "bg_play.tga");
	m_sprite2d->SetPosition(widthScreen/2, heightScreen/2);
	m_sprite2d->SetSize(widthScreen, heightScreen);

	m_button = std::make_shared<Button>("Texture", "Texture", "Load.tga");
	m_button->SetPosition(widthScreen/2, heightScreen *2/3);
	m_button->SetSize(400, 150);
	m_button->SetOnClick([]()
		{
			GameStateMachine::GetInstance()->PopState();

		});


	m_spriteAnim = std::make_shared<SpriteAnimation2D>("Texture", "Animation", "poo_down.tga", 6, 0.1f);
	m_spriteAnim->SetPosition(widthScreen/2, widthScreen/2);
	m_spriteAnim->SetSize(200, 200);

	m_text = std::make_shared<Text>("arial.ttf", "Hello", 100, glm::vec3(1.0f, 0.0f, 1.0f));
	m_text->SetPosition(200, 150);
	//ResourceManager::GetInstance()->PlaySound(AUDIO_TYPE::MUSIC, "music_game.wav");
}

void GSPlay::Update(float deltaTime)
{
	m_spriteAnim->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_sprite2d->Draw();
	m_spriteAnim->Draw();
	m_button->Draw();
	m_text->Draw();
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{

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