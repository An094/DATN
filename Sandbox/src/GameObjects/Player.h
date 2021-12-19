#pragma once
#include "DynamicObject.h"
#include "GameEngine.h"
#include <vector>
#include <queue>
#include "GameObject/Sprite2D.h"
#include "GameObject/SpriteAnimation2D.h"
class Player : public DynamicObject
{
public:
	Player(DIRECTION);
	bool IsAlive() { return isAlive; }
	void SetIsAlive(bool isA) { isAlive = isA; }

	void Init();
	void Update(float deltaTime);
	void Draw();
	void HandleKeyEvents(int key, bool bIsPressed);

	void ChangeSizeOfSprite(int newXSize, int newYSize);
private:
	bool isAlive;
	int XSpriteSize, YSpriteSize;
	std::vector<std::shared_ptr<EngineCore::Sprite2D>> m_ListSprite;
	std::queue<int> m_QueueKeyEvent; //Use in future
};

