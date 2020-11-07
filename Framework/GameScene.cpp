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
	background 
		= Push(
			new GameObject(L"resources/background.jpg"));
	background->transform->SetPosition(400.0f, 300.0f);
	background->transform->SetScale(0.8f, 0.8f);

	player
		= (Player*)Push(
			new Player(L"resources/b.png"));
	player->transform->SetPosition(400.0f, 300.0f);

	enemy = new Enemy(L"resources/a.png",100.0f);
	Push(enemy);
	enemy->transform->SetPosition(400.0f, 100.0f);
	enemy->transform->SetScale(0.5f, 0.5f);

	player->bm->enemy = enemy;

}
