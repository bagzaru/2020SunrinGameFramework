#include "stdafx.h"
#include "Enemy.h"
Enemy::Enemy(const wchar_t* imagePath, float hp)
	: GameObject(imagePath)
{
	col = new AABBCollider(
		transform,
		renderer->GetWidth()*(-0.5f),
		renderer->GetWidth()*0.5f,
		renderer->GetHeight()*(-0.5f),
		renderer->GetHeight()*0.5f
	);
	this->hp = hp;
}
Enemy::~Enemy(){
	SAFE_DELETE(col);
}
void Enemy::Hit(float damage)
{
	printf("¾Æ¾ß!\n");
	hp -= damage;
}