#pragma once
#include "GameStateManager/GameStateBase.h"
class Sprite2D;
class SpriteAnimation2D;
class Button;
class Text;
class GSIntro : public GameStateBase
{
public:
	GSIntro();
	~GSIntro();
	void Init();
	void Exit();
	void Update(float deltaTime);
	void Draw();
	void Pause();

	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
private:
	std::shared_ptr<Sprite2D> m_logo;
	float m_Time;
};

