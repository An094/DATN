#pragma once
#include "GameStateManager/GameStateBase.h"
#include "GameStateManager/GameStateMachine.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/SpriteAnimation2D.h"
#include "GameObject/Button.h"
#include "GameObject/Text.h"
#include "GameManager/ResourceManager.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/MapController.h"

class GSPlay : public EngineCore::GameStateBase
{
public:
	GSPlay();
	~GSPlay();
	void Init();
	void Exit();
	void Update(float deltaTime);
	void Draw();
	void Pause();

	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
private:
	int m_Level;
	std::shared_ptr<EngineCore::Sprite2D> m_Background;
	std::shared_ptr<MapController> m_MapController;
};