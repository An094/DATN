#pragma once
#include "GameStateManager/GameStateBase.h"
class Button;
class GSMenu : public GameStateBase
{
public:
	GSMenu() {};
	~GSMenu() {};
	void Init();
	void Exit();
	void Update(float deltaTime);
	void Draw();
	void Pause();

	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
private:
	std::shared_ptr<Button> m_buttonBack;
};

