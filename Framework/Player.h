#pragma once
#include "GameObject.h"
#include "BulletManager.h"		//여기 추가
class Player :
	public GameObject
{
public:
	Player(const wchar_t* imagePath);
	~Player();

	BulletManager* bm;		//총알 관리자 클래스
	float moveSpeed;		//이동 속도

	virtual void Update();	//업데이트 처리
	void Move();
	void Shoot();
};

