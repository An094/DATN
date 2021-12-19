#include "Player.h"
extern GLint widthScreen;
extern GLint heightScreen;
Player::Player(DIRECTION dir) : DynamicObject(), XSpriteSize(60), YSpriteSize(60)
{
	SetDirection(dir);
}

void Player::Init()
{
	std::shared_ptr<EngineCore::Sprite2D> tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_up.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, heightScreen / 2);
	tmpSprite->SetSize(XSpriteSize, YSpriteSize);
	m_ListSprite.push_back(tmpSprite);
	tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_right.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, heightScreen / 2);
	tmpSprite->SetSize(XSpriteSize, YSpriteSize);
	m_ListSprite.push_back(tmpSprite);
	tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_down.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, heightScreen / 2);
	tmpSprite->SetSize(XSpriteSize, YSpriteSize);
	m_ListSprite.push_back(tmpSprite);
	tmpSprite = std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_left.tga", "Texture", "Animation", 6, 0.1f);
	tmpSprite->SetPosition(widthScreen / 2, heightScreen / 2);
	tmpSprite->SetSize(XSpriteSize, YSpriteSize);
	m_ListSprite.push_back(tmpSprite);

	SetCurrentSprite(m_ListSprite[static_cast<int>(GetDirection())]);
}

void Player::Update(float deltaTime)
{
	SetCurrentSprite(m_ListSprite[static_cast<int>(GetDirection())]);
	GetCurrentSprite()->Update(deltaTime);
}

void Player::Draw()
{
	GetCurrentSprite()->Draw();
}

void Player::HandleKeyEvents(int key, bool isPressed)
{
	if (key == GLFW_KEY_W)
	{
		SetDirection(DIRECTION::UP);
	}
	else if (key == GLFW_KEY_D)
	{
		SetDirection(DIRECTION::RIGHT);
	}
	else if (key == GLFW_KEY_S)
	{
		SetDirection(DIRECTION::DOWN);
	}
	else if (key == GLFW_KEY_A)
	{
		SetDirection(DIRECTION::LEFT);
	}
}

void Player::ChangeSizeOfSprite(int newXSize, int newYSize)
{
	XSpriteSize = newXSize;
	YSpriteSize = newYSize;
	for (auto it : m_ListSprite)
	{
		it->SetSize(newXSize, newYSize);
	}
}