#pragma once
#include "GameObject.h"
#include "Gun.h"
#include "SoundEvent.h"

//�÷��̾� ��ü�Դϴ�.
//�̵�, �Ѿ� �߻�� �������� �� ����� ���� �����մϴ�.
//�� �ܿ� �浹ó���� ���� ȿ���� �߰��Ǿ����ϴ�.

class Player :
	public GameObject
{
public:
	Player();
	~Player();
	virtual void Update();	//������Ʈ ó��

	//Sound
	SoundEvent* se;
	SoundEvent* bgm;

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

