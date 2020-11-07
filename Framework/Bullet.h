#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Bullet :
	public GameObject
{
public:
	AABBCollider* col;
	float speed, speedRate;	//�ӵ�, ���ӵ�
	float angle, angleRate;//����, ���ӵ�
	float damage;//������

	Bullet(const wchar_t* imagePath);
	~Bullet();

	virtual void Update();
	void Move();			//�����̴��Լ�
	virtual void OnDestroy();//������ �Լ�
	virtual void OnCollision(GameObject* other);

	bool CheckOutOfScreen();	//�Ѿ� ȭ�� ����� üũ
};

