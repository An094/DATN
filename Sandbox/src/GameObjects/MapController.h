#pragma once
#include <vector>
#include "GameObject/Sprite2D.h"
#include "DynamicObject.h"
#include "Enemy.h"
#include "Player.h"
#define TILEMAP_SIZE 48

typedef struct Point 
{
	int x, y;
};

typedef struct DynamicObjectData
{
	Point StartPoint, EndPoint;
	DIRECTION Direction;
};

typedef struct TileMap
{
	int ID;
	bool isWall;
	Point point;
	int width, height;
	int xPos, yPos;
	std::shared_ptr<EngineCore::Sprite2D> sprite;
};

class MapController
{
public:
	MapController(int level);
	~MapController();
	void DrawMap();
	void Update(float deltaTime);
	void Draw();
	void HandleKeyEvent(int key, bool isPressed);
	DynamicObjectData GetPlayerData();
	std::shared_ptr<Player> GetPlayer() { return m_Player; }
	bool CheckCollision(std::shared_ptr<DynamicObject> obj1, std::shared_ptr<DynamicObject> obj2);
	int CheckCollisionWithWall(std::shared_ptr<TileMap>& tileMap);
private:
	int m_Level;
	std::vector<std::shared_ptr<TileMap>> m_ListTileMap;
	DynamicObjectData m_PlayerData;
	std::shared_ptr<Player> m_Player;
	std::vector<std::shared_ptr<Enemy>> m_ListEnemies;
	int m_KeyPressed;
	int** TileMapMatrix;
	int length, height;
};

