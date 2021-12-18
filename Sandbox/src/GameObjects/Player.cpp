#include "Player.h"
extern GLint widthScreen;
Player::Player() : DynamicObject()
{

}

void Player::Init()
{
	std::shared_ptr<EngineCore::Sprite2D> tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_left.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, widthScreen / 2);
	tmpSprite->SetSize(200, 200);
	m_ListSprite.push_back(tmpSprite);
	tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_up.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, widthScreen / 2);
	tmpSprite->SetSize(200, 200);
	m_ListSprite.push_back(tmpSprite);
	tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_right.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, widthScreen / 2);
	tmpSprite->SetSize(200, 200);
	m_ListSprite.push_back(tmpSprite);
	tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_down.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, widthScreen / 2);
	tmpSprite->SetSize(200, 200);
	m_ListSprite.push_back(tmpSprite);

	SetCurrentSprite(m_ListSprite[0]);
}

void Player::Update(float deltaTime)
{
	GetCurrentSprite()->Update(deltaTime);
	if (m_Key == GLFW_KEY_A)
	{
		SetCurrentSprite(m_ListSprite[0]);
	}
	else if (m_Key == GLFW_KEY_W)
	{
		SetCurrentSprite(m_ListSprite[1]);
	}
	else if (m_Key == GLFW_KEY_D)
	{
		SetCurrentSprite(m_ListSprite[2]);
	}
	else if (m_Key == GLFW_KEY_S)
	{
		SetCurrentSprite(m_ListSprite[3]);
	}
	m_Key = 0;
}

void Player::Draw()
{
	GetCurrentSprite()->Draw();
}

void Player::HandleKeyEvents(int key, bool isPressed)
{
	m_Key = key;
}