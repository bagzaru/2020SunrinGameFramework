#include "stdafx.h"
#include "Enemy.h"
#include "Scene.h"

Enemy::Enemy(const wchar_t* imagePath, float moveSpeed, int hp)
	: GameObject(imagePath),hp(hp),moveSpeed(moveSpeed)
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