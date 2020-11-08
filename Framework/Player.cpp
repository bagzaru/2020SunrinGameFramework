#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Bullet.h"
#include "Scene.h"

Player::Player()
	:GameObject(L"resources/Player.png"),
	moveSpeed(300.0f), timer(0.0f), delay(3.0f), angle(0.0f)
{
	tag = Tag::Player;
	gun = new Gun(0.5f, 1000.0f, 3, 0.1f * PI);
	col = new AABBCollider(this, renderer);
	Scene::PushOnCurrentScene(col);
}
Player::~Player()
{
	SAFE_DELETE(gun);
}
void Player::Update() {
	//매 프레임 호출
	Move();
	Shoot();
	//SetCameraOnPlayer();
	CollisionTimer();
}



void Player::Move()
{
	//움직임을 담당
	Vector2 input(0.0f, 0.0f);

	if (InputManager::GetKeyState('S'))
	{
		input.y -= 1.0f;
	}
	if (InputManager::GetKeyState('D'))
	{
		input.x += 1.0f;
	}
	if (InputManager::GetKeyState('W'))
	{
		input.y += 1.0f;
	}
	if (InputManager::GetKeyState('A'))
	{
		input.x -= 1.0f;
	}
	if (input.x!=0.0f||input.y!=0.0f)
	{
		input = input.normalized();
		transform->position.x += moveSpeed * input.x * TimeManager::GetDeltaTime();
		transform->position.y += moveSpeed * input.y * TimeManager::GetDeltaTime();
	}
}

void Player::Shoot()
{
	gun->UpdateDelay();
	angle = ComputeMouseAngle();
	if (InputManager::GetKeyDown(VK_LBUTTON))
	{
		gun->Shoot(transform->position, angle);
	}
	transform->rotatingAngle = angle;
}

void Player::SetCameraOnPlayer()
{
	Camera::GetCamera()->transform->position = transform->position;
}

float Player::ComputeMouseAngle()
{
	Vector2 mouse(
		(float)InputManager::GetMouseX(),
		(float)InputManager::GetMouseY()
	);
	Vector2 mouseInWorld = Camera::ScreenPositionToWorld(mouse);
	//printf("%.2f, %.2f\n", mouseInWorld.x, mouseInWorld.y);
	return atan2f(
		mouseInWorld.y - transform->position.y,
		mouseInWorld.x - transform->position.x);
}

void Player::OnCollision(GameObject* other)
{
	if (timer > delay && other->tag == Tag::Enemy)
	{
		//hp -= 1;
		std::cout << "체력이 1 달았습니다. 현재" << hp << "남음\n";
		timer = 0;
	}
	if (hp == 0)
	{
		std::cout << "게임 오바";
		Scene::Destroy(this);
	}
}

void Player::CollisionTimer()
{
	if (timer <= delay)
	{
		timer += TimeManager::GetDeltaTime();
	}
}

