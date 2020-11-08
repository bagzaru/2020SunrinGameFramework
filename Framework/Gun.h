#pragma once
#include "Bullet.h"
class Gun
{
public:
	//�� �Ӽ�
	int bulletCount;
	float bulletGap;
	float bulletSpeed;

	//�Ѿ� ������ ���
	float timer;
	float delay;
	bool canShoot;
public:
	Gun(float delay, float bulletSpeed = 1000.0f, int bulletCount = 1, float bulletGap = 0.1f);

	void UpdateDelay();
	void Shoot(Vector2 playerPosition, float angle);
};

