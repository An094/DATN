#include "MapController.h"
#include "GameEngine.h"
#include <fstream>

extern GLint widthScreen;
extern GLint heightScreen;

MapController::MapController(int level)
{
	m_Level = level;
	std::string pathMapFile = "../Data/Maps/0" + std::to_string(level) + ".txt";
	std::fstream input(pathMapFile);
	if (input.fail())
	{
		CLIENT_ERROR("Openning file Map is error");
	}
	int tmp, i = 0;
	int iDataFileArray[1024];
	while (input >> tmp)
	{
		iDataFileArray[i++] = tmp;
	}

	int it = 0;

	m_PlayerData.StartPoint.x = iDataFileArray[it++];
	m_PlayerData.StartPoint.y = iDataFileArray[it++];
	m_PlayerData.Direction = static_cast<DIRECTION>(iDataFileArray[it++]);
	m_PlayerData.EndPoint.x = iDataFileArray[it++];
	m_PlayerData.EndPoint.y = iDataFileArray[it++];

	//Initialize Player
	m_Player = std::make_shared<Player>(m_PlayerData.Direction);
	m_Player->Init();
	m_Player->SetIsAlive(true);

	int length, height;
	length = iDataFileArray[it++];
	height = iDataFileArray[it++];
	int** TileMapMatrix = new int* [height];
	for (int i = 0; i < height; i++)
	{
		TileMapMatrix[i] = new int[length];
	}

	char TileMapName[12];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			int tmp = iDataFileArray[it++];
			TileMapMatrix[i][j] = tmp;
			sprintf_s(TileMapName, "Tile/%02d.tga", tmp);
			std::shared_ptr<EngineCore::Sprite2D> tmpSprite = std::make_shared<EngineCore::Sprite2D>(std::string(TileMapName));
			tmpSprite->SetSize(TILEMAP_SIZE, TILEMAP_SIZE);
			int posX, posY;
			posX = (j - m_PlayerData.StartPoint.x) * TILEMAP_SIZE + 300;
			posY = (i - m_PlayerData.StartPoint.y) * TILEMAP_SIZE + 400;
			tmpSprite->SetPosition(posX, posY);
			m_ListTileMap.push_back(tmpSprite);
		}
	}

	int numberEnemies = iDataFileArray[it++];



	//Deallocate 
	for (int i = 0; i < height; i++)
	{
		delete TileMapMatrix[i];
	}
	delete[]TileMapMatrix;
}

DynamicObjectData MapController::GetPlayerData()
{
	return m_PlayerData;
}

void MapController::DrawMap()
{
	for (auto it : m_ListTileMap)
	{
		it->Draw();
	}
}

void MapController::Draw()
{
	DrawMap();
	m_Player->Draw();
}

void MapController::Update(float deltaTime)
{
	m_Player->Update(deltaTime);
}

void MapController::HandleKeyEvent(int key, bool isPressed)
{
	m_Player->HandleKeyEvents(key, isPressed);
}