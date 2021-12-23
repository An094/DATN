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

	length = iDataFileArray[it++];
	height = iDataFileArray[it++];
	TileMapMatrix = new int* [height];
	for (int i = 0; i < height; i++)
	{
		TileMapMatrix[i] = new int[length];
	}

	char TileMapName[12];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			std::shared_ptr<TileMap> tmpTileMap = std::make_shared<TileMap>();

			int tmp = iDataFileArray[it++];
			TileMapMatrix[i][j] = tmp;

			sprintf_s(TileMapName, "Tile/%02d.tga", tmp);
			std::shared_ptr<EngineCore::Sprite2D> tmpSprite = std::make_shared<EngineCore::Sprite2D>(std::string(TileMapName));
			tmpSprite->SetSize(TILEMAP_SIZE, TILEMAP_SIZE);
			int posX, posY;
			posX = (j - m_PlayerData.StartPoint.x) * TILEMAP_SIZE + 300;
			posY = (i - m_PlayerData.StartPoint.y) * TILEMAP_SIZE + 400;
			tmpSprite->SetPosition(posX, posY);

			if ((tmp == 0) || (tmp == 23) || (tmp == 24) || (tmp == 25) || (tmp == 26) || (tmp == 27) || (tmp == 36))
			{
				tmpTileMap->isWall = false;
			}
			else
			{
				tmpTileMap->isWall = true;
			}

			tmpTileMap->ID = tmp;
			tmpTileMap->width = TILEMAP_SIZE;
			tmpTileMap->height = TILEMAP_SIZE;
			tmpTileMap->point.x = j;
			tmpTileMap->point.y = i;
			tmpTileMap->xPos = posX;
			tmpTileMap->yPos = posY;
			tmpTileMap->sprite = tmpSprite;

			m_ListTileMap.push_back(tmpTileMap);
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

			int distaneToPlayerX = (startX - m_PlayerData.StartPoint.x) * TILEMAP_SIZE + widthScreen / 2;
			int distaneToPlayerY = (startY - m_PlayerData.StartPoint.y) * TILEMAP_SIZE + heightScreen / 2;

			std::shared_ptr<Soldier> tmpSoldier = std::make_shared<Soldier>(static_cast<DIRECTION>(direction), maxDistance, 100.0f);
			tmpSoldier->SetPosition(distaneToPlayerX, distaneToPlayerY);
			tmpSoldier->SetSize(60, 60);

			m_ListEnemies.push_back(tmpSoldier);
		}
	}

	int numberGolds = iDataFileArray[it++];
	remainingGold = numberGolds;
	if (numberEnemies == 0) return;
	for (int i = 0; i < numberGolds; i++)
	{
		std::shared_ptr<Gold> tmpGold = std::make_shared<Gold>();
		int x = iDataFileArray[it++];
		int y = iDataFileArray[it++];

		int distaneToPlayerX = (x - m_PlayerData.StartPoint.x) * TILEMAP_SIZE + widthScreen / 2;
		int distaneToPlayerY = (y - m_PlayerData.StartPoint.y) * TILEMAP_SIZE + heightScreen / 2;
		tmpGold->SetPosition(distaneToPlayerX, distaneToPlayerY);
		tmpGold->SetSize(36);
		m_ListGolds.push_back(tmpGold);
	}

}

MapController::~MapController()
{
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
		it->sprite->Draw();
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
	for (auto it : m_ListGolds)
	{
		it->Draw();
	}
}

void MapController::Update(float deltaTime)
{
	std::shared_ptr<EngineCore::OrthographicCamera> cam = EngineCore::Application::GetInstance()->GetCamera();
	std::shared_ptr<TileMap> colliderTileMap;
	//
	int collider = CheckCollisionWithWall(colliderTileMap);

	glm::vec2 playerPosition = m_Player->GetPosition();
	if ((collider == 6) || (collider == 1))
	{
		if (playerPosition.x > colliderTileMap->xPos)
		{
			m_Player->CanLeft = false;
			cam->CanMoveLeft = false;
		}
	}
	if ((collider == 5) || (collider == 10))
	{
		if (playerPosition.x < colliderTileMap->xPos)
		{
			m_Player->CanRight = false;
			cam->CanMoveRight = false;
		}
	}
	if ((collider == 1) || (collider == 5))
	{
		if (playerPosition.y > colliderTileMap->yPos)
		{
			m_Player->CanUp = false;
			cam->CanMoveUp = false;
		}
	}
	if ((collider == 6) || (collider == 10))
	{
		if (playerPosition.y < colliderTileMap->yPos)
		{
			m_Player->CanDown = false;
			cam->CanMoveDown = false;
		}
	}
	if ((collider == 3) || (collider == 28) || (collider == 29))
	{
		m_Player->CanUp = false;
		cam->CanMoveUp = false;
	}
	if ((collider == 8) || (collider == 30) || (collider == 31))
	{
		m_Player->CanDown = false;
		cam->CanMoveDown = false;
	}
	if ((collider == 11) || (collider == 32) || (collider == 33))
	{
		m_Player->CanLeft = false;
		cam->CanMoveLeft = false;
	}
	if ((collider == 12) || (collider == 34) || (collider == 35))
	{
		m_Player->CanRight = false;
		cam->CanMoveRight = false;
	}
	m_Player->Update(deltaTime);

	m_Player->CanUp = true;
	m_Player->CanRight = true;
	m_Player->CanDown = true;
	m_Player->CanLeft = true;

	cam->Update(deltaTime);

	cam->CanMoveUp = true;
	cam->CanMoveRight = true;
	cam->CanMoveDown = true;
	cam->CanMoveLeft = true;

	CheckCollectGold();
	WinGame();
	for (auto it : m_ListEnemies)
	{
		if (CheckCollision(m_Player, it))
		{
			m_Player->Die();
			cam->CanMove = false;
			//CLIENT_INFO("COLLISION OCCUR");
		}
		it->Update(deltaTime);
	}

	for (auto it : m_ListGolds)
	{
		it->Update(deltaTime);
	}
}

void MapController::HandleKeyEvent(int key, bool isPressed)
{
	m_Player->HandleKeyEvents(key, isPressed);
	//Camera
	std::shared_ptr<EngineCore::OrthographicCamera> cam = EngineCore::Application::GetInstance()->GetCamera();
	cam->HandleKeyEvents(key, isPressed);
	m_KeyPressed = key;
}

bool MapController::CheckCollision(std::shared_ptr<DynamicObject> obj1, std::shared_ptr<DynamicObject> obj2)
{
	int deltaCollision = 35;
	glm::vec2 pos1 = obj1->GetPosition();
	glm::vec2 pos2 = obj2->GetPosition();

	int width1, width2, height1, height2;
	obj1->GetSize(width1, height1);
	obj2->GetSize(width2, height2);

	int top1 = pos1.y - height1 / 2;
	int bot1 = top1 + height1;
	int left1 = pos1.x - width1 / 2;
	int right1 = left1 + width1;

	int top2 = pos2.y - height2 / 2;
	int bot2 = top2 + height2;
	int left2 = pos2.x - width2 / 2;
	int right2 = left2 + width2;

	if (top1 + deltaCollision > bot2 || bot1 - deltaCollision < top2 || left1 + deltaCollision > right2 || right1 - deltaCollision < left2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int MapController::CheckCollisionWithWall(std::shared_ptr<TileMap>& tile)
{
	int topPlayer = m_Player->GetPosition().y + 15;
	int botPlayer = topPlayer + 15;
	int leftPlayer = m_Player->GetPosition().x - 15;
	int rightPlayer = leftPlayer + 30;

	for (auto it : m_ListTileMap)
	{
		if (it->isWall)
		{
			int topWall = it->yPos - 24;
			int botWall = topWall + 48;
			int leftWall = it->xPos - 24;
			int rightWall = leftWall + 48;

			if (topPlayer > botWall || botPlayer < topWall || leftPlayer > rightWall || rightPlayer < leftWall)
			{
				continue;
			}
			else
			{
				//std::cout << "COLLISION: " << it->point.x << it->point.y << std::endl;
				tile = it;
				//std::cout << it->ID << std::endl;
				return it->ID;
			}
		}
	}
	return 0;
}

void MapController::CheckCollectGold()
{
	int topPlayer = m_Player->GetPosition().y - 15;
	int botPlayer = topPlayer + 30;
	int leftPlayer = m_Player->GetPosition().x - 15;
	int rightPlayer = leftPlayer + 30;
	for (auto it : m_ListGolds)
	{
		if (!it->isActive) continue;
		int topGold = it->GetPosition().y - 10;
		int botGold = topGold + 20;
		int leftGold = it->GetPosition().x - 10;
		int rightGold = leftGold + 20;

		if (topPlayer > botGold || botPlayer < topGold || leftPlayer > rightGold || rightPlayer < leftGold)
		{
			continue;
		}
		else
		{
			it->Disable();
			remainingGold--;
		}
	}
}

bool MapController::WinGame()
{
	if (remainingGold != 0)
	{
		return false;
	}

	int playerXPosition = m_Player->GetPosition().x;
	int playerYPosition = m_Player->GetPosition().y;

	int topEndPoint = (m_PlayerData.EndPoint.y - m_PlayerData.StartPoint.y) * TILEMAP_SIZE + heightScreen / 2 - TILEMAP_SIZE / 2;
	int botEndPoint = topEndPoint + TILEMAP_SIZE;
	int leftEndPoint = (m_PlayerData.EndPoint.x - m_PlayerData.StartPoint.x) * TILEMAP_SIZE + widthScreen / 2 - TILEMAP_SIZE / 2;
	int rightEndPoint = leftEndPoint + TILEMAP_SIZE;

	if ((playerYPosition > topEndPoint) && (playerYPosition < botEndPoint) && (playerXPosition > leftEndPoint) && (playerXPosition <rightEndPoint))
	{
		CLIENT_INFO("WIN GAME");
		return true;
	}


}