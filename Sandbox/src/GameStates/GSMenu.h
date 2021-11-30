#pragma once
#include "GameStateManager/GameStateBase.h"
class Button;
class Sprite2D;
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
	std::shared_ptr<Sprite2D> m_Background;
	std::shared_ptr<Sprite2D> m_Logo;
	std::shared_ptr<Button> m_PlayButton;
	std::shared_ptr<Button> m_SettingButton;
	std::shared_ptr<Button> m_QuitButton;
};

