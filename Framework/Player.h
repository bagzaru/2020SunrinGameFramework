#pragma once
#include "GameObject.h"
#include "BulletManager.h"		//여기 추가
#include "Gun.h"
class Player :
	public GameObject
{
public:
	Player(const wchar_t* imagePath);
	~Player();

	float moveSpeed;		//이동 속도
	int hp = 3;
	Gun* gun;
	AABBCollider* col;

	virtual void Update();	//업데이트 처리
	void Move();
	void Shoot();
	void SetCameraOnPlayer();
	float ComputeMouseAngle();

	float timer;
	float delay;
	void OnCollision(GameObject* other);
	void CollisionTimer();
};

