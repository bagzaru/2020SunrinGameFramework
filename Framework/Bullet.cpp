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
		renderer->GetWidth() * 0.5f,
		renderer->GetHeight() * (-0.5f),
		renderer->GetHeight() * 0.5f
	);
	Scene::PushOnCurrentScene(col);
	speed = 0.0f;
	speedRate = 0.0f;
	angle = 0.0f;
	angleRate = 0.0f;
	damage = 0.0f;
	tag = 1;
}
void Bullet::Move()
{
	float rad = PI * angle * 2.0f;

	transform->position.x
		+= (speed * cosf(rad) * TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sinf(rad) * TimeManager::GetDeltaTime());

	speed += speedRate * TimeManager::GetDeltaTime();
	angle += angleRate * TimeManager::GetDeltaTime();
}

Bullet::~Bullet() {
	SAFE_DELETE(col);
}


void Bullet::OnDestroy() {
	printf("����");
}

void Bullet::OnCollision(GameObject* other)
{
	if(other->tag==2)
		Scene::Destroy(this);
}

bool Bullet::CheckOutOfScreen()
{
	//�Ѿ��� �����ǰ�, �Ѿ��� �̹��� ũ�⸦ ����ؼ�
	//�Ѿ��� �ۿ� ������ �� �������־�� ��.
	int sw = WinApp::GetScreenWidth();					//�������� ���� ����
	int sh = WinApp::GetScreenHeight();					//�������� ���� ����
	int bw = renderer->GetWidth() * transform->scale.x;	//�̹����� ���� ����*������
	int bh = renderer->GetHeight() * transform->scale.y;//�̹����� ���� ����*������

	return transform->position.x<bw * (-1.0f) ||	//�Ѿ��� ���� ���� �����ų�
		transform->position.x>bw + sw ||			//�Ѿ��� ���� ���� �����ų�
		transform->position.y<bh * (-1.0f) ||		//�Ѿ��� ���� ���� �����ų�
		transform->position.y>bh + sh;				//�Ѿ��� �Ʒ� ���� �����ų�

}

void Bullet::Update()
{
	Move();
}

