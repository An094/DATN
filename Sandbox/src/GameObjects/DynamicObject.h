#pragma once
#include "GameObject/Sprite2D.h"

enum  class DIRECTION
{
	UP = 0,
	RIGHT,
	DOWN,
	LEFT
};
class DynamicObject
{
public:
	DynamicObject() = default;
	virtual ~DynamicObject() = default;
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;


	inline void SetDirection(DIRECTION dir) { m_Dir = dir; }
	DIRECTION GetDirection() const { return m_Dir; }
	void SetPosition(const glm::vec2& pos) { m_Sprite->SetPosition(pos); }
	glm::vec2 GetPosition() const { return m_Sprite->GetPosition(); }
	void SetCurrentSprite(const std::shared_ptr<EngineCore::Sprite2D>& sprite);
	std::shared_ptr<EngineCore::Sprite2D> GetCurrentSprite();
private:
	DIRECTION m_Dir;
	std::shared_ptr<EngineCore::Sprite2D> m_Sprite;
};

