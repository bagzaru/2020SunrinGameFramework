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
	Scene::GetCurrentScene()->Push(bm);
}
Player::~Player() {}
void Player::Update() {
	//�� ������ ȣ��
	Move();
}



void Player::Move() {
	//�������� ���
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
	//�Ѿ� �߻�
	//for (float i = 0.0f; i < 1.0f; i += 0.05f)
	//{
		Bullet* b = new Bullet(L"resources/b.png");
		Scene::GetCurrentScene()->Push(b);
		bm->PushBackBullet(b);

		b->transform->position = this->transform->position;
		b->transform->SetScale(0.2f, 0.2f);
		b->speed = 100.0f;
		b->angleRate = 0.05f;
		b->angle = 0.75f;
	//}
}

