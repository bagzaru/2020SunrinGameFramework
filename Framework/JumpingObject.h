#pragma once
#include "GameObject.h"
#include "Ground.h"

//점핑오브젝트
//점프하는 오브젝트입니다.

class JumpingObject :
	public GameObject
{
public:
	//점프와 관련된 변수입니다.
	float moveSpeed;	//좌우 이동 속도
	float jumpSpeed;	//현재 점프중인 속도(y축 속도)
	float gravity;	//현재 점프에 적용중인 가속도(y축 가속도)
	float jumpPower;	//점프시의 파워
	bool isJumping;		//점프 중인가 체크

	AABBCollider* col;	//충돌체

public:
	JumpingObject();
	~JumpingObject();

	void Update();			//매 프레임 호출되는 업데이트 함수
	void Move();			//좌우 이동
	void Jump();			//점프 이동
	bool CheckOnGround(Ground* ground);	//땅 위인지 체크
	void OnCollision(GameObject* other);

	Ground* currentGround;	//현재 밟고 있는 땅

};

