#pragma once
#include "Scene.h"
#include "Player.h"		
#include "Enemy.h"
#include "EnemySpawner.h"

//4,5���� ���� �ð��� �Բ� ������ Scene�Դϴ�.

class GameScene : public Scene
{
public:
	virtual void Initialize();

	GameObject* background;	//��� �̹���
	Player* player;		//�÷��̾�
	Enemy* enemy;		//��
	EnemySpawner* spawner;
};

