#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Enemy :
	public GameObject
{
public:
	AABBCollider* col;

	int hp;
	float moveSpeed;

	Enemy(const wchar_t* imagePath, float moveSpeed, int hp);
	void Hit(float damage);
	~Enemy();
	void OnCollision(GameObject* other);
};

