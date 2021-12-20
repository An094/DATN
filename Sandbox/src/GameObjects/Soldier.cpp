#include "Soldier.h"
#include "GameManager/ResourceManager.h"
#include "GameObject/SpriteAnimation2D.h"
Soldier::Soldier(DIRECTION dir, float maxD, float speed) 
	: Enemy(ENEMY_TYPE::SOLDIER, dir, speed), m_MaxDistance(maxD), m_Distance(0.0f)
{
	std::shared_ptr<EngineCore::Texture> tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Enemy/enemy0_up.tga");
	m_ListTexture.push_back(tmpTexture);
	tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Enemy/enemy0_right.tga");
	m_ListTexture.push_back(tmpTexture);
	tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Enemy/enemy0_down.tga");
	m_ListTexture.push_back(tmpTexture);
	tmpTexture = EngineCore::ResourceManager::GetInstance()->GetTexture("Enemy/enemy0_left.tga");
	m_ListTexture.push_back(tmpTexture);

	SetSprite(std::make_shared<EngineCore::SpriteAnimation2D>("Enemy/enemy0_up.tga", "Texture", "Animation", 8, 0.1f));
	SetCurrentTexture(m_ListTexture[static_cast<int>(dir)]);
}

void Soldier::Update(float deltaTime)
{
	GetSprite()->Update(deltaTime);
}

void Soldier::Draw()
{
	GetSprite()->Draw();
}

void Soldier::HandleKeyEvents(int key, bool isPress)
{

}