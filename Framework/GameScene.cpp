#include "stdafx.h"
#include "GameScene.h"
#include "ScoreManager.h"


void GameScene::Initialize()
{
	//배경, 플레이어, 적, spawner, scoreManager를 생성하고 Scene에 Push합니다.
	background = Push(new GameObject(L"resources/background.png"));
	player = (Player*)Push(new Player());
	enemy = new Enemy(L"resources/Enemy.png",100.0f,30,player->transform);
	Push(enemy);
	enemy->transform->SetPosition(0.0f, 300.0f);

	spawner = new EnemySpawner(player->transform);
	Push(spawner);

	PushUI(new ScoreManager());


	subCamera = new SubCamera(Vector2(100.0f, 100.0f), GetD2DApp());
	subCamera->transform->SetPosition(50.0f, 50.0f);
	subCamera->target = player->transform;
	Push(subCamera);

}
