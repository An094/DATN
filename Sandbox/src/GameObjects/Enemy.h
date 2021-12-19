#pragma once
#include "DynamicObject.h"
enum class ENEMY_TYPE
{
	STRAIGHT = 0,
	TRAP,
	RING
};
class Enemy : public DynamicObject
{
public:
	Enemy() : DynamicObject() {}
	virtual ~Enemy() = default;
	void SetType(ENEMY_TYPE type) { m_Type = type; }
	ENEMY_TYPE GetType() { return m_Type; }
private:
	ENEMY_TYPE m_Type;
};

