#include "stdafx.h"
#include "GameScene.h"
#include "ScoreManager.h"


void GameScene::Initialize()
{
	//���, �÷��̾�, ��, spawner, scoreManager�� �����ϰ� Scene�� Push�մϴ�.
	background = Push(new GameObject(L"resources/background.png"));
	player = (Player*)Push(new Player());
	enemy = new Enemy(L"resources/Enemy.png",100.0f,30,player->transform);
	Push(enemy);
	enemy->transform->SetPosition(0.0f, 300.0f);

	spawner = new EnemySpawner(player->transform);
	Push(spawner);

	PushUI(new ScoreManager());


	subScreen = new SubScreen(Vector2(150.0f, 150.0f), GetD2DApp());
	subScreen->transform->SetPosition(75.0f, 75.0f);
	subScreen->target = player->transform;
	Push(subScreen);

}
