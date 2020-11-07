#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Enemy :
	public GameObject
{
public:
	float hp;
	AABBCollider* col;

	void OnCollision(GameObject* other);

	Enemy(const wchar_t* imagePath, float hp);
	void Hit(float damage);
	~Enemy();
};

