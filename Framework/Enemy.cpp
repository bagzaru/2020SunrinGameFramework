#include "stdafx.h"
#include "Enemy.h"
#include "Scene.h"
#include "TimeManager.h"

Enemy::Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform)
	: GameObject(imagePath),hp(hp),moveSpeed(moveSpeed), playerTransform(playerTransform)
{
	col = new AABBCollider(
		this,
		renderer
	);
	cc = new CircleCollider(this,(float)renderer->GetWidth());
	//Scene::PushOnCurrentScene(col);
	Scene::PushOnCurrentScene(cc);

	tag = Tag::Enemy;
}

Enemy::~Enemy(){
	SAFE_DELETE(col);
	SAFE_DELETE(cc);
}

void Enemy::Update()
{
	Move();
}

void Enemy::Move()
{
	Vector2 aim = (playerTransform->position - transform->position).normalized();
	transform->SetRotation(atan2f(aim.y, aim.x));
	transform->position.x += aim.x * moveSpeed * TimeManager::GetDeltaTime();
	transform->position.y += aim.y * moveSpeed * TimeManager::GetDeltaTime();
}

void Enemy::OnCollision(GameObject* other)
{
	if (other->tag == Tag::Bullet)
	{
		--hp;
		std::cout << "���� �¾ҽ��ϴ� �� hp: " << hp << "\n";
	}
	if (hp <= 0)
	{
		Scene::Destroy(this);
	}
}