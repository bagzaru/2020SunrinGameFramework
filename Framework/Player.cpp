#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "Scene.h"

Player::Player(const wchar_t* imagePath)
	:GameObject(imagePath)
{
	moveSpeed = 500.0f;
	bm = new BulletManager();
	Scene::GetCurrentScene()->PushBackGameObject(bm);
}
Player::~Player() {}
void Player::Update() {
	//매 프레임 호출
	Move();
}



void Player::Move() {
	//움직임을 담당
	if (InputManager::GetKeyState(VK_UP))
		transform->position.y -= moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_DOWN))
		transform->position.y += moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_RIGHT))
		transform->position.x += moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_LEFT))
		transform->position.x -= moveSpeed * TimeManager::GetDeltaTime();

	if (InputManager::GetKeyState(VK_SPACE))
	{
		Shoot();
	}
}

void Player::Shoot() {
	//총알 발사
	for (float i = 0.0f; i < 1.0f; i += 0.05f)
	{
		Bullet* b = new Bullet(L"resources/b.png");
		Scene::GetCurrentScene()->PushBackGameObject(b);
		bm->PushBackBullet(b);

		b->transform->position = this->transform->position;
		b->transform->SetScale(0.2f, 0.2f);
		b->speed = 1000.0f;
		b->angleRate = 0.05f;
		b->angle = i;
	}
}

