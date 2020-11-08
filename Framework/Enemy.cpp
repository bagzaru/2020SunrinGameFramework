#include "stdafx.h"
#include "Enemy.h"
#include "Scene.h"
#include "TimeManager.h"

Enemy::Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform)
	: GameObject(imagePath),hp(hp),moveSpeed(moveSpeed), playerTransform(playerTransform)
{
	col = new AABBCollider(
		this,
		renderer->GetWidth()*(-0.5f),
		renderer->GetHeight()*(-0.5f),
		renderer->GetWidth() * 0.5f,
		renderer->GetHeight()*0.5f
	);
	Scene::PushOnCurrentScene(col);

	tag = Tag::Enemy;
}

Enemy::~Enemy(){
	SAFE_DELETE(col);
}

void Enemy::Update()
{
	Move();
}

void Enemy::Move()
{
	Vector2 aim = (playerTransform->position - transform->position).normalize();
	transform->position.x += aim.x * moveSpeed * TimeManager::GetDeltaTime();
	transform->position.y += aim.y * moveSpeed * TimeManager::GetDeltaTime();
}

void Enemy::Hit(float damage)
{
	//printf("아야!\n");
	//hp -= damage;
}


void Enemy::OnCollision(GameObject* other)
{
	if (other->tag == Tag::Bullet)
	{
		--hp;
		std::cout << "적이 맞았습니다 적 hp: " << hp << "\n";
	}
	if (hp <= 0)
	{
		Scene::Destroy(this);
	}
}