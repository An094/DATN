#include "MapController.h"
#include "GameEngine.h"
#include "Application.h"
#include "GameObject/OrthographicCamera.h"
#include "Soldier.h"
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
	for (int i = 0; i < numberEnemies; i++)
	{
		int type = iDataFileArray[it++];
		
		if (type == 0)
		{
			int startX = iDataFileArray[it++];
			int startY = iDataFileArray[it++];
			int direction = iDataFileArray[it++];
			int maxDistance = iDataFileArray[it++] * TILEMAP_SIZE;

			int distaneToPlayerX = (startX - m_PlayerData.StartPoint.x) * TILEMAP_SIZE + widthScreen/2;
			int distaneToPlayerY = (startY - m_PlayerData.StartPoint.y) * TILEMAP_SIZE + heightScreen/2; 

			std::shared_ptr<Soldier> tmpSoldier = std::make_shared<Soldier>(static_cast<DIRECTION>(direction), maxDistance, 100.0f);
			tmpSoldier->SetPosition(distaneToPlayerX, distaneToPlayerY);
			tmpSoldier->SetSize(60, 60);

			m_ListEnemies.push_back(tmpSoldier);
		}
	}


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

	for (auto it : m_ListEnemies)
	{
		it->Draw();
	}
}

void MapController::Update(float deltaTime)
{
	std::shared_ptr<EngineCore::OrthographicCamera> cam = EngineCore::Application::GetInstance()->GetCamera();
	if (m_KeyPressed == GLFW_KEY_W)
	{
		m_Player->MoveUp(deltaTime);
		cam->MoveUp(deltaTime);
	}
	else if (m_KeyPressed == GLFW_KEY_D)
	{
		m_Player->MoveRight(deltaTime);
		cam->MoveRight(deltaTime);
	}
	else if (m_KeyPressed == GLFW_KEY_S)
	{
		m_Player->MoveDown(deltaTime);
		cam->MoveDown(deltaTime);
	}
	else if (m_KeyPressed == GLFW_KEY_A)
	{
		m_Player->MoveLeft(deltaTime);
		cam->MoveLeft(deltaTime);
	}
	m_KeyPressed = 0;
	m_Player->Update(deltaTime);

	for (auto it : m_ListEnemies)
	{
		if(CheckCollision(m_Player, it))
		{
			CLIENT_INFO("COLLISION OCCUR");
		}
		it->Update(deltaTime);
	}
}

void MapController::HandleKeyEvent(int key, bool isPressed)
{
	m_Player->HandleKeyEvents(key, isPressed);
	//Camera
	m_KeyPressed = key;
}

bool MapController::CheckCollision(std::shared_ptr<DynamicObject> obj1, std::shared_ptr<DynamicObject> obj2)
{
	int deltaCollision = 20;
	glm::vec2 pos1 = obj1->GetPosition();
	glm::vec2 pos2 = obj2->GetPosition();
	
	int width1, width2, height1, height2;
	obj1->GetSize(width1, height1);
	obj2->GetSize(width2, height2);

	int top1 = pos1.y + height1 / 2;
	int bot1 = top1 - height1;
	int left1 = pos1.x - width1 / 2;
	int right1 = left1 + width1;

	int top2 = pos2.y + height2 / 2;
	int bot2 = top2 - height2;
	int left2 = pos2.x - width2 / 2;
	int right2 = left2 + width2;

	if (top1 - deltaCollision < bot2 || bot1 + deltaCollision> top2 || left1 + deltaCollision > right2 || right1 - deltaCollision < left2)
	{
		return false;
	}
	else
	{
		return true;
	}
}