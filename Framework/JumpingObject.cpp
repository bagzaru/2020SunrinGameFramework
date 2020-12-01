#include "stdafx.h"
#include "JumpingObject.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Scene.h"

JumpingObject::JumpingObject()
	:GameObject(L"resources/Player.png"), moveSpeed(300.0f), jumpPower(2000.0f),
	isJumping(false), gravity(10000.0f), jumpSpeed(0.0f), currentGround(nullptr)
{
	col = new AABBCollider(this, renderer);
	Scene::PushOnCurrentScene(col);
}

JumpingObject::~JumpingObject()
{
	SAFE_DELETE(col);
}

void JumpingObject::Update()
{
	Move();
	Jump();
}

void JumpingObject::Move()
{
	//�¿� �̵� �ڵ��Դϴ�.
	if (InputManager::GetKeyState(VK_LEFT))
	{
		transform->position.x -= moveSpeed * TimeManager::GetDeltaTime();
	}
	if (InputManager::GetKeyState(VK_RIGHT))
	{
		transform->position.x += moveSpeed * TimeManager::GetDeltaTime();
	}
}

void JumpingObject::Jump()
{
	if (!currentGround)
	{
		//currentGround�� null�� ���,
		//�浹 ó�� �˻� �Ŀ��� ���� ���� ���� �ʾҴٴ� ���̹Ƿ�
		//���� ���� ���� ������ �Ǵ��մϴ�.
		isJumping = true;
	}
	else
	{
		//�� ���� ������, �������� �ʽ��ϴ�.
		isJumping = false;
		jumpSpeed = 0.0f;
	}

	//�����̽�Ű�� ������ ��� �����մϴ�.
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		isJumping = true;
		jumpSpeed = jumpPower;
	}

	//���� ���� ���, jumpAccel�� �߷� ������ �����ϰ� �߷��� ����մϴ�.
	if (isJumping)
	{
		transform->position.y += jumpSpeed * TimeManager::GetDeltaTime();
		jumpSpeed -= gravity * TimeManager::GetDeltaTime();
	}
	//currentGround�� ���۴ϴ�. ��� �浹 ���� ��� ���� �浹 �˻�� ���ŵ˴ϴ�.
	currentGround = nullptr;
}

bool JumpingObject::CheckOnGround(Ground* ground)
{
	if (jumpSpeed > 0.0f)
	{
		//���� �ӵ��� ������ ���� ���� ���̹Ƿ� false
		return false;
	}
	if (ground->CheckStand(this->col, jumpSpeed * TimeManager::GetDeltaTime()))
	{
		//���� ���� �� �ٴ� ���� �ִ� ������ ������ �Ǿ��ٸ�.
		//���� ���� �� �ٴ����� �����ϰ�,
		//���� �� �������� '�� �������� ���κ� + �÷��̾� �߽ɺ��� �߱����� �Ÿ�'�� �����մϴ�.
		transform->position.y
			= ground->transform->position.y
			+ ground->col->boundingBox.leftTop.y * ground->transform->scale.y
			- col->boundingBox.rightBottom.y * transform->scale.y;

		//�� ���� �����Ƿ� true�� ��ȯ�մϴ�.
		return true;
	}
	//�� ���� �ƴϹǷ� false�� ��ȯ�մϴ�.
	return false;
}

void JumpingObject::OnCollision(GameObject* other)
{
	if (other->tag == Tag::Ground)
	{
		//�浹�� ����� ground�̹Ƿ�, CheckOnGround�� �����մϴ�.
		//���� �� ���� �ִٸ�, �ش� �� ���� �ִ� ������ currentGround�� ����մϴ�.
		//Update�� Jump���� �� ���� �ִٸ�, �ڵ����� ������ ���� �ݴϴ�.
		if (CheckOnGround((Ground*)other))
		{
			currentGround = (Ground*)other;
		}
	}
}
