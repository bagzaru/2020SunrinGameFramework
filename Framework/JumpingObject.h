#pragma once
#include "GameObject.h"
#include "Ground.h"

//���ο�����Ʈ
//�����ϴ� ������Ʈ�Դϴ�.

class JumpingObject :
	public GameObject
{
public:
	//������ ���õ� �����Դϴ�.
	float moveSpeed;	//�¿� �̵� �ӵ�
	float jumpSpeed;	//���� �������� �ӵ�(y�� �ӵ�)
	float gravity;	//���� ������ �������� ���ӵ�(y�� ���ӵ�)
	float jumpPower;	//�������� �Ŀ�
	bool isJumping;		//���� ���ΰ� üũ

	AABBCollider* col;	//�浹ü

public:
	JumpingObject();
	~JumpingObject();

	void Update();			//�� ������ ȣ��Ǵ� ������Ʈ �Լ�
	void Move();			//�¿� �̵�
	void Jump();			//���� �̵�
	bool CheckOnGround(Ground* ground);	//�� ������ üũ
	void OnCollision(GameObject* other);

	Ground* currentGround;	//���� ��� �ִ� ��

};

