#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Scene.h"
#define PI 3.141592f
Bullet::Bullet(const wchar_t* imagePath)
	:GameObject(imagePath)
{
	col = new AABBCollider(
		this,
		renderer->GetWidth() * (-0.5f),
		renderer->GetHeight() * (-0.5f),
		renderer->GetWidth() * 0.5f,
		renderer->GetHeight() * 0.5f
	);
	Scene::PushOnCurrentScene(col);
	speed = 0.0f;
	speedRate = 0.0f;
	angle = 0.0f;
	angleRate = 0.0f;
	damage = 0.0f;
	tag = Tag::Bullet;
}


void Bullet::Move()
{
	transform->position.x
		+= (speed * cosf(angle) * TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sinf(angle) * TimeManager::GetDeltaTime());

	speed += speedRate * TimeManager::GetDeltaTime();
	angle += angleRate * TimeManager::GetDeltaTime();
}

Bullet::~Bullet() {
	SAFE_DELETE(col);
}


void Bullet::OnDestroy() {
	printf("으앙");
}

void Bullet::OnCollision(GameObject* other)
{
	if(other->tag==Tag::Enemy)
		Scene::Destroy(this);
}

void Bullet::CheckOutOfScreen()
{
	if (!Camera::GetCamera()->IsOnScreen(col))
	{
		printf("화면 밖에 나감!\n");
		Scene::Destroy(this);
	}

	//총알의 포지션과, 총알의 이미지 크기를 고려해서
	//총알이 밖에 나갔는 지 판정해주어야 함.
	//int sw = WinApp::GetScreenWidth();					//윈도우의 가로 길이
	//int sh = WinApp::GetScreenHeight();					//윈도우의 세로 길이
	//int bw = renderer->GetWidth() * transform->scale.x;	//이미지의 가로 길이*스케일
	//int bh = renderer->GetHeight() * transform->scale.y;//이미지의 세로 길이*스케일

	//return transform->position.x<bw * (-1.0f) ||	//총알이 왼쪽 끝을 나갔거나
	//	transform->position.x>bw + sw ||			//총알이 오른 끝을 나갔거나
	//	transform->position.y<bh * (-1.0f) ||		//총알이 위쪽 끝을 나갔거나
	//	transform->position.y>bh + sh;				//총알이 아래 끝을 나갔거나

}

void Bullet::Update()
{
	Move();
	CheckOutOfScreen();
}

