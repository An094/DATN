#pragma once
#include "GameStateManager/GameStateBase.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/SpriteAnimation2D.h"
#include "GameObject/Button.h"
#include "GameObject/Text.h"
#include "GameManager/ResourceManager.h"
#include "Utils/Log.h"
class GSIntro : public EngineCore::GameStateBase
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
	std::shared_ptr<EngineCore::Sprite2D> m_logo;
	float m_Time;
};

