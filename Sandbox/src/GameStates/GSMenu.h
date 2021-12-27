#pragma once
#include "GameStateManager/GameStateBase.h"
#include "GameObject/Button.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameManager/ResourceManager.h"
#include "GameObject/Texture.h"

class GSMenu : public EngineCore::GameStateBase
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
	std::shared_ptr<EngineCore::Sprite2D> m_Background;
	std::shared_ptr<EngineCore::Sprite2D> m_Logo;
	std::shared_ptr<EngineCore::Button> m_PlayButton;
	std::shared_ptr<EngineCore::Button> m_CreditButton;
	std::shared_ptr<EngineCore::Button> m_SettingButton;
	std::shared_ptr<EngineCore::Button> m_QuitButton;

	bool logoGoDown;
	float speedLogo;
};

