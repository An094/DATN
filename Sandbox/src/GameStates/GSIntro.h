#pragma once
#include "GameStateManager/GameStateBase.h"
class Sprite2D;
class SpriteAnimation2D;
class Button;
class GSIntro : public GameStateBase
{
public:
	GSIntro();
	~GSIntro();
	void Init();
	void Exit();
	void Update(float deltaTime);
	void Draw();

	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
private:
	std::shared_ptr<Sprite2D> m_sprite2d;
	std::shared_ptr<SpriteAnimation2D> m_spriteAnim;

	std::shared_ptr<Button> m_button;
};

