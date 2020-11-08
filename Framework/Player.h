#pragma once
#include "GameObject.h"
#include "BulletManager.h"		//���� �߰�
#include "Gun.h"
class Player :
	public GameObject
{
public:
	Player();
	~Player();
	virtual void Update();	//������Ʈ ó��

	//�̵�
	float moveSpeed;		//�̵� �ӵ�
	void Move();

	//�Ѿ� �߻�
	Gun* gun;
	void Shoot();
	float ComputeMouseAngle();

	//���Ϳ� �浹
	int hp = 3;
	AABBCollider* col;
	float timer;
	float delay;
	void OnCollision(GameObject* other);
	void CollisionTimer();
};

