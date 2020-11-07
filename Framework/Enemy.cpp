#include "stdafx.h"
#include "Enemy.h"
#include "Scene.h"
void Enemy::OnCollision(GameObject* other)
{
	//if(other->tag = 1)
		//Hit(20.0f);
}
Enemy::Enemy(const wchar_t* imagePath, float hp)
	: GameObject(imagePath)
{
	col = new AABBCollider(
		this,
		renderer->GetWidth()*(-0.5f),
		renderer->GetWidth()*0.5f,
		renderer->GetHeight()*(-0.5f),
		renderer->GetHeight()*0.5f
	);
	Scene::PushOnCurrentScene(col);
	this->hp = hp;
	tag = 2;
}
Enemy::~Enemy(){
	SAFE_DELETE(col);
}
void Enemy::Hit(float damage)
{
	printf("¾Æ¾ß!\n");
	hp -= damage;
}