#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
class Enemy :
	public GameObject
{
public:
	Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform);
	~Enemy();
	void Update();

	//�浹 ���� �Լ�
	void OnCollision(GameObject* other);

	//�Ѿ˰� �浹
	int hp;

	//�÷��̾ ���� �̵�
	float moveSpeed;
	Transform* playerTransform;
	void Move();

	//�÷��̾�� �浹
	AABBCollider* col;
};

