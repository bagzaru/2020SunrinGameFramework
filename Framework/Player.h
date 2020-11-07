#pragma once
#include "GameObject.h"
#include "BulletManager.h"		//���� �߰�
class Player :
	public GameObject
{
public:
	Player(const wchar_t* imagePath);
	~Player();

	BulletManager* bm;		//�Ѿ� ������ Ŭ����
	float moveSpeed;		//�̵� �ӵ�

	virtual void Update();	//������Ʈ ó��
	void Move();
	void Shoot();
};

