#include "Player.h"
#include "GameManager/ResourceManager.h"
extern GLint widthScreen;
extern GLint heightScreen;
Player::Player(DIRECTION dir) : DynamicObject(dir, 150.f) , isAlive(true), KEY(0), CanUp(true), CanRight(true), CanDown(true), CanLeft(true)
{
	std::shared_ptr<EngineCore::Texture> tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Poo/poo_up.tga");
	m_ListTexture.push_back(tmpTexture);
	tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Poo/poo_right.tga");
	m_ListTexture.push_back(tmpTexture);
	tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Poo/poo_down.tga");
	m_ListTexture.push_back(tmpTexture);
	tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Poo/poo_left.tga");
	m_ListTexture.push_back(tmpTexture);

	SetSprite(std::make_shared<EngineCore::SpriteAnimation2D>("Poo/poo_up.tga", "Texture", "Animation", 6, 0.1f));
	SetCurrentTexture(m_ListTexture[static_cast<int>(GetDirection())]);
	SetSize(70, 70);
	SetPosition(widthScreen / 2, heightScreen / 2);
}

void Player::Update(float deltaTime)
{
	//std::cout << "Can Up: " << CanUp << std::endl;
	//std::cout << "Can Down: " << CanDown << std::endl;
	if (KEY == GLFW_KEY_W && CanUp && isAlive)
	{
		SetDirection(DIRECTION::UP);
		SetCurrentTexture(m_ListTexture[0]);
		MoveUp(deltaTime);
	}
	else if (KEY == GLFW_KEY_D && CanRight && isAlive)
	{
		SetDirection(DIRECTION::RIGHT);
		SetCurrentTexture(m_ListTexture[1]);
		MoveRight(deltaTime);
	}
	else if (KEY == GLFW_KEY_S && CanDown && isAlive)
	{
		SetDirection(DIRECTION::DOWN);
		SetCurrentTexture(m_ListTexture[2]);
		MoveDown(deltaTime);
	}
	else if (KEY == GLFW_KEY_A && CanLeft && isAlive)
	{
		SetDirection(DIRECTION::LEFT);
		SetCurrentTexture(m_ListTexture[3]);
		MoveLeft(deltaTime);
	}
	GetSprite()->Update(deltaTime);
}

void Player::Draw()
{
	GetSprite()->Draw();
}

void Player::HandleKeyEvents(int key, bool isPressed)
{
	if (isPressed)
	{
		KEY = key;
	}
	else
	{
		KEY = 0;
	}
}


void Player::MoveUp(float deltaTime)
{
	glm::vec2 currentPos = GetPosition();
	currentPos[1] -= GetSpeed() * deltaTime;
	SetPosition(currentPos);
}

void Player::MoveRight(float deltaTime)
{
	glm::vec2 currentPos = GetPosition();
	currentPos[0] += GetSpeed() * deltaTime;
	SetPosition(currentPos);
}

void Player::MoveDown(float deltaTime)
{
	glm::vec2 currentPos = GetPosition();
	currentPos[1] += GetSpeed() * deltaTime;
	SetPosition(currentPos);
}

void Player::MoveLeft(float deltaTime)
{
	glm::vec2 currentPos = GetPosition();
	currentPos[0] -= GetSpeed() * deltaTime;
	SetPosition(currentPos);
}

void Player::Die()
{
	SetCurrentTexture(EngineCore::ResourceManager::GetInstance()->GetTexture("Poo/poo_dead.tga"));
	isAlive = false;
}