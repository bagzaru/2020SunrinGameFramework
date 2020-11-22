#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//적 객체입니다. 움직이고, 총알에 피격합니다.
class Enemy :
	public GameObject
{
public:
	Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform);
	~Enemy();
	void Update();

	//충돌 관련 함수
	//OnCollision: 충돌이 감지되었을 때 호출됩니다.
	void OnCollision(GameObject* other);

	//총알과 충돌
	int hp;

	//플레이어를 향해 이동
	float moveSpeed;
	Transform* playerTransform;
	void Move();

	//플레이어와 충돌
	AABBCollider* col;
};

