#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
class Bullet :
	public GameObject
{
public:
	AABBCollider* col;
	float speed, speedRate;	//�ӵ�, ���ӵ�
	float angle, angleRate;//����, ���ӵ�

	Bullet(const wchar_t* imagePath);
	~Bullet();

	virtual void Update();

	//�Ѿ��� �̵�
	void Move();			//�����̴��Լ�

	//�Ѿ��� �浹
	void CheckOutOfScreen();	//�Ѿ� ȭ�� ����� üũ
	virtual void OnCollision(GameObject* other);
	virtual void OnDestroy();//������ �Լ�
};

