#pragma once
#include "Bullet.h"
class Gun
{
public:
	float timer;
	float delay;
	int bulletCount;
	float bulletGap;
	float bulletSpeed;
	bool canShoot;
public:
	Gun(float delay, float bulletSpeed = 1000.0f, int bulletCount = 1, float bulletGap = 0.1f);

	void UpdateDelay();
	void Shoot(Vector2 playerPosition, float angle);
};

