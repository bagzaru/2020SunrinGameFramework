#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//�Ѿ� ��ü�Դϴ�.
//����, �ӵ� ���� ���� ������ ������ ���ư��ϴ�.
//���� ���� ��� �浹�մϴ�.

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

	//OnCollision: �浹�� �����Ǿ��� �� ȣ��˴ϴ�.
	virtual void OnCollision(GameObject* other);
	//OnDestroy: ���ӿ�����Ʈ�� ������ �� ȣ��˴ϴ�.
	virtual void OnDestroy();//������ �Լ�
};

