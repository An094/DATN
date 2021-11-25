#include "GSIntro.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/SpriteAnimation2D.h"
#include "GameObject/Button.h"
#include "GameObject/Text.h"
#include "GameManager/ResourceManager.h"
GSIntro::GSIntro()
{

}

GSIntro::~GSIntro()
{

}

void GSIntro::Init()
{
	m_sprite2d = std::make_shared<Sprite2D>("Texture", "Texture", "bg_play.tga");
	m_sprite2d->SetPosition(400, 400);
	m_sprite2d->SetSize(800, 800);

	m_button = std::make_shared<Button>("Texture", "Texture", "Load.tga");
	m_button->SetPosition(400, 600);
	m_button->SetSize(400, 150);
	m_button->SetOnClick([]()
		{
			//std::cout << "Button is clicked" << std::endl;
			GameStateMachine::GetInstance()->ChangeState(1);
			
		});


	m_spriteAnim = std::make_shared<SpriteAnimation2D>("Texture", "Animation", "poo_down.tga", 6, 0.1f);
	m_spriteAnim->SetPosition(400, 400);
	m_spriteAnim->SetSize(200, 200);

	m_text = std::make_shared<Text>("arial.ttf", "Hello", 100, glm::vec3(1.0f, 0.0f, 1.0f));
	m_text->SetPosition(300, 200);
	ResourceManager::GetInstance()->PlaySound("music_game.wav");
}

void GSIntro::Update(float deltaTime)
{
	m_spriteAnim->Update(deltaTime);
}

void GSIntro::Draw()
{
	m_sprite2d->Draw();
	m_spriteAnim->Draw();
	m_button->Draw();
	m_text->Draw();
}

void GSIntro::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSIntro::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	m_button->HandleTouchEvent(x, y, bIsPressed);
}

void GSIntro::Pause()
{

}

void GSIntro::Exit()
{

}