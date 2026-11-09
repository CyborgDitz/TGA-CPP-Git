#Helicopter
# #header
```Cpp

#pragma once
#include "PongData.h"
#include <tge/sprite/sprite.h>
#include <random>
#include <string>
#include <tge/text/text.h>
#include <vector>
#include <tge/application.h>

namespace Tga
{
	class InputManager;
}

class GameWorld
{
public:
	GameWorld(); 
	~GameWorld();

	void Init();

	void Update(float aTimeDelta, Tga::InputManager& aInputManager);
	void Render();
	bool HasPlayerCollided();
	void UpdateScore();
	void LoseGame();
	void Restart();
private:

	Tga::Application& myApplication;
	Tga::Vector2f myResolution;

	std::vector<PongData::SpriteObject>myObstacles;

	void SetResolution();

	PongData::SpriteObject myPlayerTemplate =
	{
		// 2x1 scale
		.spriteAdress = "Sprites/Helicopter.png",
		.spriteInstance{
			.position = {0.25f, 0.5f},
			.pivot = {0.5f,0.5f},
			.size = {0.2f, 0.1f},
			.color = {1.0f, 0.0f, 1.0f, 1.0f}
		},
		.direction = {0.0f,1.0f},
		.speed = 0.4f
	};

	PongData::SpriteObject* myPlayer;
	//PongData::SpriteObject myPlayer = myPlayerTemplate;

	PongData::SpriteObject myObstacleTemplate =
	{
		// 1x2 scale
		.spriteAdress = "Sprites/MetalBlock.png",
		.spriteInstance{
			.position = {1.0f, 0.5f},
			.pivot = {0.5f,0.5f},
			.size = {0.1f, 0.05f},
			.color = {1.0f, 0.0f, 1.0f, 1.0f}
		},
		.direction = {-1.0f, 0.0f},
		.speed = 0.2f
	};

	Tga::Sprite2DInstanceData myTGELogoInstance = {};
	Tga::SpriteSharedData mySharedData = {};

	PongData::Score myScore;
	Tga::Text myPlayerScoreText;
	Tga::Text myBotScoreText;
	Tga::Text myScreenText;

	//const int myWinCondition = 3;
	bool myHasILost = false;

};

//const int myWinValue = 3;

void MoveObject(PongData::SpriteObject& aObject, float aScreenHeight, float aTimeDelta);
bool IsRectCollision(PongData::SpriteObject aSpriteObject0, PongData::SpriteObject aSpriteObject1);

float RandomNumber();
```

# 
#  #cpp
```cpp
#include "GameWorld.h"
#include "PongData.h"
#include "Timer.h"
#include <tge/graphics/GraphicsEngine.h>
#include <tge/drawers/SpriteDrawer.h>
#include <tge/texture/TextureManager.h>
#include <tge/drawers/DebugDrawer.h>
#include <tge/input/InputManager.h>
#include <tge/application.h>
#include <random>
#include <iostream>

#include "TemplateUtilities.h"

using namespace Tga;

GameWorld::GameWorld() :
	myApplication(*Tga::Application::GetInstance()),
	myPlayerScoreText("Text/arial.ttf", Tga::FontSize_48), myBotScoreText("Text/arial.ttf", Tga::FontSize_48),
	myScreenText("Text/arial.ttf", Tga::FontSize_72)
{

}

GameWorld::~GameWorld()
{}
bool IsRectsCollide(Tga::Sprite2DInstanceData aSprite0, Tga::Sprite2DInstanceData aSprite1)
{

	if (aSprite0.position.x >= aSprite1.position.x - (aSprite0.size.x / 2))
	{
		return true;
	}
	else if (aSprite0.position.x <= 0 + (aSprite1.size.x / 2))
	{
		return true;
	}

	return false;
}

void GameWorld::Init()
{

	SetResolution();

	{
		mySharedData.texture = GraphicsEngine::GetInstance()->GetTextureManager().GetTexture("Sprites/tge_logo_w.dds");
		myTGELogoInstance.pivot = { 0.5f, 0.5f };
		myTGELogoInstance.position = Tga::Vector2f{ 0.5f, 0.5f } * myResolution;
		myTGELogoInstance.size = Tga::Vector2f{ 0.75f, 0.75f } * myResolution.y;
		myTGELogoInstance.color = Tga::Color(1, 1, 1, 1);

		myScore.player = 0;
		myPlayerScoreText.SetText(std::to_string(0));
		myPlayerScoreText.SetPosition(Tga::Vector2f{ 0.33f, 0.9f } * myResolution);

		myScreenText.SetText("Qrikkopter");
		myScreenText.SetColor(Tga::Color(1.0f, 0.6f, 0.8f, 0.8f));
		myScreenText.SetPosition(Tga::Vector2f{ 0.5, 0.75 } * myResolution);
	}

	PongData::SpriteObject* spriteObjectsInitArray[] = { &myPlayerTemplate, &myObstacleTemplate };
	int spriteObjectArraySize = 2;

	for (int i = 0; i < spriteObjectArraySize; i++)
	{
		spriteObjectsInitArray[i]->spriteShared.texture = GraphicsEngine::GetInstance()->GetTextureManager().GetTexture(spriteObjectsInitArray[i]->spriteAdress);
		spriteObjectsInitArray[i]->spriteInstance.position *= myResolution;
		spriteObjectsInitArray[i]->spriteInstance.size *= myResolution.y;
	}
	myObstacleTemplate.spriteInstance.size.y = myResolution.y;


	myPlayer = new PongData::SpriteObject(myPlayerTemplate);

	// default pos.x 0.5

} 

void GameWorld::Update(float aTimeDelta, Tga::InputManager& aInputManager)
{
	//UNREFERENCED_PARAMETER(aTimeDelta);
	//UNREFERENCED_PARAMETER(aInputManager);

	//gameLoop bool
	if (myHasILost == false)
	{
		MoveObject(*myPlayer, myResolution.y, aTimeDelta);
		MoveObject(myObstacleTemplate, myResolution.y, aTimeDelta);
		UpdateScore();
		if (HasPlayerCollided()== true)
		{
			LoseGame();
		}
	}

	if (myHasILost && aInputManager.IsKeyPressed(VK_RETURN)
	{
		Restart();
	}
	/*

	bool botWantsToMove = false;
	if (myBotPaddle.spriteInstance.position.y < myPlayer->spriteInstance.position.y)
	{
		myBotPaddle.direction.y = 1;
		botWantsToMove = true;
	}
	else if (myBotPaddle.spriteInstance.position.y > myPlayer->spriteInstance.position.y)
	{
		myBotPaddle.direction.y = -1;
		botWantsToMove = true;
	}
	if (botWantsToMove && myHasILost == false)
	{
		MoveObject(myBotPaddle, myResolution.y, aTimeDelta);
	}

	*/
	if (aInputManager.IsKeyHeld('W' || VK_SPACE))
	{
		myPlayer->direction.y = 1;
	}
	else
	{
		myPlayer->direction.y = -1;
	}
	if (myHasILost == false)
	{
		MoveObject(*myPlayer, myResolution.y, aTimeDelta);
	}

	//Ball collider

		// Qrikko brackets for seperation fun

	//win or lose

}

void GameWorld::LoseGame()
{
	myHasILost = true;
	myPlayerScoreText.SetText("You crashed the Qrikkopter!!");
	std::cout << "You crashed the Qrikkopter!!" << '\n';
}
bool GameWorld::HasPlayerCollided()
{
	const PongData::Bounds playerBounds = myPlayer->GetBounds();
	
	if (IsRectCollision(*myPlayer, myObstacleTemplate) || playerBounds.up >= myResolution.y || playerBounds.down <= 0)
	{
		return true;
	}
	return false;
}

void GameWorld::SetResolution()
{
	Tga::Vector2ui intResolution = myApplication.GetRenderSize();
	myResolution =  { (float)intResolution.x, (float)intResolution.y };
}

void GameWorld::UpdateScore()
{
	if (myPlayer->speed <= 0)
	{
		++myScore.player;
		myPlayerScoreText.SetText(std::to_string(myScore.player));
		std::cout << "Player Score : " << myScore.player << '\n';
	}
}
void GameWorld::Restart()
{
	{
		delete myPlayer;
		myPlayer = new PongData::SpriteObject(myPlayerTemplate);

	}
	{
		myObstacleTemplate.spriteInstance.position ={ 0.0f,0.5f };
	}
	//score
	{
		myScore.player = 0;
	
		myPlayerScoreText.SetText("0");
	}

	myHasILost = false;
}

void MoveObject(PongData::SpriteObject& aObject, float aScreenHeight, float aTimeDelta)
{
	aObject.spriteInstance.position += (aObject.direction * aObject.speed) * aScreenHeight * aTimeDelta;
}

bool IsRectCollision(PongData::SpriteObject aSpriteObject0, PongData::SpriteObject aSpriteObject1)
{
	PongData::Bounds spriteObject0Bounds = aSpriteObject0.GetBounds();
	PongData::Bounds spriteObject1Bounds = aSpriteObject1.GetBounds();

	//Qrikketed
	{
		return
			spriteObject0Bounds.right >= spriteObject1Bounds.left &&
			spriteObject0Bounds.left <= spriteObject1Bounds.right &&
			spriteObject0Bounds.up >= spriteObject1Bounds.down &&
			spriteObject0Bounds.down <= spriteObject1Bounds.up;
	}

}

float RandomNumber()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_real_distribution<float> dis(0.0f, 1.0f);

	float randomNumb = dis(gen);
	return randomNumb;
}

void GameWorld::Render()
{
	auto& graphicsEngine = *Tga::GraphicsEngine::GetInstance();

	Tga::SpriteDrawer& spriteDrawer(graphicsEngine.GetSpriteDrawer());
	// Game update
	{
		for (size_t i = 0; i < myObstacles.size(); i++)
		{
			spriteDrawer.Draw(myObstacles[i].spriteShared, myObstacles[i].spriteInstance);
		}
		spriteDrawer.Draw(myPlayer->spriteShared, myPlayer->spriteInstance);
		spriteDrawer.Draw(myObstacleTemplate.spriteShared, myObstacleTemplate.spriteInstance);

		spriteDrawer.Draw(mySharedData, myTGELogoInstance);

		myPlayerScoreText.Render();
		myScreenText.SetColor({ 0.5f, 0.5f, 0.5f, 1.0f });
		myScreenText.Render();
	}
	// Debug draw pivot
#ifndef _RETAIL
	{
		Tga::DebugDrawer& dbg = graphicsEngine.GetDebugDrawer();
		Tga::Color c1 = myTGELogoInstance.color;
		dbg.DrawCircle(myTGELogoInstance.position, 5.f, (c1.myR + c1.myG + c1.myB) / 3 > 0.3f ? Tga::Color(0, 0, 0, 1) : Tga::Color(1, 1, 1, 1));
	}
#endif

}