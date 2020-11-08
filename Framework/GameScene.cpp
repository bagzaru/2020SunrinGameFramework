#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	background = Push(new GameObject(L"resources/background.jpg"));
	player = (Player*)Push(new Player(L"resources/b.png"));
	enemy = new Enemy(L"resources/a.png",100.0f,30,player->transform);
	Push(enemy);
	enemy->transform->SetPosition(0.0f, 300.0f);
	enemy->transform->SetScale(0.5f, 0.5f);
}
