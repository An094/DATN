#pragma once
#include "Enemy.h"
#include "GameObject/Texture.h"
#include <vector>
class Soldier : public Enemy
{
public:
	Soldier(DIRECTION dir, float maxD, float speed);
	void Update(float deltaTime) override;
	void Draw() override;
	void HandleKeyEvents(int key, bool isPressed) override;
private:
	float m_MaxDistance;
	std::vector<std::shared_ptr<EngineCore::Texture>> m_ListTexture;
	float m_Distance;
};

