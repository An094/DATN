#include "DynamicObject.h"

void DynamicObject::SetCurrentSprite(const std::shared_ptr<EngineCore::Sprite2D>& sprite)
{
	m_Sprite = sprite;
}

std::shared_ptr<EngineCore::Sprite2D> DynamicObject::GetCurrentSprite()
{
	return m_Sprite;
}