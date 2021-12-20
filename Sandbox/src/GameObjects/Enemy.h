#pragma once
#include "DynamicObject.h"
enum class ENEMY_TYPE
{
	SOLDIER = 0,
	TRAP,
	RING
};
class Enemy : public DynamicObject
{
public:
	Enemy(ENEMY_TYPE type, DIRECTION dir, float speed) : DynamicObject(dir, speed), m_Type(type) {}
	virtual ~Enemy() = default;

	virtual void Update(float) = 0;
	virtual void Draw() = 0;
	virtual void HandleKeyEvents(int, bool) = 0;
	void SetType(ENEMY_TYPE type) { m_Type = type; }
	ENEMY_TYPE GetType() { return m_Type; }
private:
	ENEMY_TYPE m_Type;
};

