#pragma once
#include "GameObject.h"
#include "BulletManager.h"		//���� �߰�
#include "Gun.h"
class Player :
	public GameObject
{
public:
	Player(const wchar_t* imagePath);
	~Player();

	float moveSpeed;		//�̵� �ӵ�
	int hp = 3;
	Gun* gun;
	AABBCollider* col;

	virtual void Update();	//������Ʈ ó��
	void Move();
	void Shoot();
	void SetCameraOnPlayer();
	float ComputeMouseAngle();

	float timer;
	float delay;
	void OnCollision(GameObject* other);
	void CollisionTimer();
};

