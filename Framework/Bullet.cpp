#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Scene.h"


Bullet::Bullet(const wchar_t* imagePath)
	:GameObject(imagePath)
{
	//�浹ü�� �����մϴ�.
	col = new AABBCollider(this,renderer);
	//�浹ü�� Scene�� ����մϴ�.
	Scene::PushOnCurrentScene(col);

	//��Ÿ ������ �ʱ�ȭ�մϴ�.
	speed = 0.0f;
	speedRate = 0.0f;
	angle = 0.0f;
	angleRate = 0.0f;

	//tag�� ����մϴ�. �浹 ó���� ���˴ϴ�.
	tag = Tag::Bullet;
}

Bullet::~Bullet() {
	//�浹ü�� �����ϸ� �ݵ�� ���� ������ �־�� �մϴ�.
	SAFE_DELETE(col);
}

void Bullet::Update()
{
	Move();
	CheckOutOfScreen();
}

void Bullet::Move()
{
	//position�� ����, �ӵ��� ���� ������Ʈ�Ͽ� �����Դϴ�.
	transform->position.x
		+= (speed * cosf(angle) * TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sinf(angle) * TimeManager::GetDeltaTime());

	speed += speedRate * TimeManager::GetDeltaTime();
	angle += angleRate * TimeManager::GetDeltaTime();
}

void Bullet::CheckOutOfScreen()
{
	//ȭ�� ������ �������� ���θ� üũ�մϴ�.
	if (!Camera::GetCamera()->IsOnScreen(col))
	{
		//printf("ȭ�� �ۿ� ����!\n");
		Scene::Destroy(this);
	}
}

//OnCollision: �浹�� �����Ǿ��� �� ȣ��˴ϴ�.
void Bullet::OnCollision(GameObject* other)
{
	//�浹�� ����� ���� ��� �Ѿ��� �����մϴ�.
	if (other->tag == Tag::Enemy)
	{
		Scene::Destroy(this);
	}
}

//OnDestroy: ���ӿ�����Ʈ�� ������ �� ȣ��˴ϴ�.
void Bullet::OnDestroy() {
	//std::cout << "�Ѿ� ������ �Ф�\n";
}
