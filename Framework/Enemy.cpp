#include "stdafx.h"
#include "Enemy.h"
#include "Scene.h"
#include "TimeManager.h"
#include "ScoreManager.h"

Enemy::Enemy(const wchar_t* imagePath, float moveSpeed, int hp, Transform* playerTransform)
	: GameObject(imagePath),hp(hp),moveSpeed(moveSpeed), playerTransform(playerTransform)
{
	//�浹�� �����ϱ� ���� �浹ü�� �����մϴ�.
	col = new AABBCollider(
		this,
		renderer
	);
	//�浹ü�� ���� Scene�� �߰��մϴ�.
	Scene::PushOnCurrentScene(col);

	//�� ������Ʈ�� Tag�� ����մϴ�. Enemy�� ����Ͽ����ϴ�. ���� �浹ó�� �� ����մϴ�.
	tag = Tag::Enemy;
}

Enemy::~Enemy(){
	//�浹ü�� ����� ��� �ݵ�� �ʱ�ȭ�� �ʿ��մϴ�.
	SAFE_DELETE(col);
}

void Enemy::Update()
{
	Move();
}

void Enemy::Move()
{
	Vector2 aim = (playerTransform->position - transform->position).normalized();
	transform->SetRotation(atan2f(aim.y, aim.x));
	transform->position.x += aim.x * moveSpeed * TimeManager::GetDeltaTime();
	transform->position.y += aim.y * moveSpeed * TimeManager::GetDeltaTime();
}

//OnCollision: �浹�� �����Ǿ��� �� ȣ��˴ϴ�.
void Enemy::OnCollision(GameObject* other)
{
	//�浹ü�� Bullet�� ��쿡�� ü���� ����ϴ�.
	if (other->tag == Tag::Bullet)
	{
		--hp;
	}

	//ü���� 0���� ���� ��� ������ ���ϰ� �� ��ü�� �����մϴ�.
	if (hp <= 0)
	{
		Scene::Destroy(this);
		ScoreManager::AddScore(10);
	}
}