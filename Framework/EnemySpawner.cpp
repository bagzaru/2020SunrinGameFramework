#include "stdafx.h"
#include "EnemySpawner.h"
#include "TimeManager.h"
#include "Scene.h"
#include "Random.h"

EnemySpawner::EnemySpawner(Transform* playerTransform) 
	: GameObject(), timer(0.0f), playerTransform(playerTransform)
{
	spawnDelay = 1.0f;
}

EnemySpawner::~EnemySpawner()
{
}

//�ð��� ������Ʈ�մϴ�.
//���� spawnDelay�� ������ ���, ���� �����մϴ�.
void EnemySpawner::Update()
{
	UpdateTimer();
	if (timer > spawnDelay)
	{
		Spawn();
	}
}

void EnemySpawner::UpdateTimer()
{
	timer += TimeManager::GetDeltaTime();
}

void EnemySpawner::Spawn()
{

	//�� ������Ʈ�� ����ϴ�.
	Enemy* enemy = new Enemy(L"resources/Enemy.png", 100.0f, 5, playerTransform);

	//������ ��ġ�� �����մϴ�. x������ -500~500, y������ -500~500 ��ġ �� �������� �����ǰ� �˴ϴ�.
	Vector2 v(Random::Range(-500.0f, 500.0f), Random::Range(-500.0f, 500.0f));
	enemy->transform->SetPosition(v);
	//std::cout << "���� ����: " << v.x << ", " << v.y << "\n";

	//���� Scene�� Push�մϴ�.
	Scene::PushOnCurrentScene(enemy);

	//���͸� �����Ͽ����Ƿ� ���� Ÿ�̸Ӹ� �ٽ� �ʱ�ȭ�մϴ�.
	timer = 0.0f;
}
