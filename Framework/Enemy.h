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
	Transform* playerTransform;

	Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform);
	void Hit(float damage);
	~Enemy();
	void Update();
	void Move();
	void OnCollision(GameObject* other);
	
};

