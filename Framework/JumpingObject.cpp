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
	//좌우 이동 코드입니다.
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
		//currentGround가 null일 경우,
		//충돌 처리 검사 후에도 발판 위에 있지 않았다는 뜻이므로
		//현재 점프 중인 것으로 판단합니다.
		isJumping = true;
	}
	else
	{
		//땅 위에 있으면, 점프하지 않습니다.
		isJumping = false;
		jumpSpeed = 0.0f;
	}

	//스페이스키가 눌렸을 경우 점프합니다.
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		isJumping = true;
		jumpSpeed = jumpPower;
	}

	//점프 중일 경우, jumpAccel을 중력 값으로 생각하고 중력을 계산합니다.
	if (isJumping)
	{
		transform->position.y += jumpSpeed * TimeManager::GetDeltaTime();
		jumpSpeed -= gravity * TimeManager::GetDeltaTime();
	}
	//currentGround를 없앱니다. 계속 충돌 중일 경우 다음 충돌 검사시 갱신됩니다.
	currentGround = nullptr;
}

bool JumpingObject::CheckOnGround(Ground* ground)
{
	if (jumpSpeed > 0.0f)
	{
		//점프 속도가 양수라면 위로 점프 중이므로 false
		return false;
	}
	if (ground->CheckStand(this->col, jumpSpeed * TimeManager::GetDeltaTime()))
	{
		//만약 현재 이 바닥 위에 있는 것으로 판정이 되었다면.
		//현재 땅을 이 바닥으로 설정하고,
		//현재 내 포지션을 '땅 포지션의 윗부분 + 플레이어 중심부터 발까지의 거리'로 설정합니다.
		transform->position.y
			= ground->transform->position.y
			+ ground->col->boundingBox.leftTop.y * ground->transform->scale.y
			- col->boundingBox.rightBottom.y * transform->scale.y;

		//땅 위에 있으므로 true를 반환합니다.
		return true;
	}
	//땅 위가 아니므로 false를 반환합니다.
	return false;
}

void JumpingObject::OnCollision(GameObject* other)
{
	if (other->tag == Tag::Ground)
	{
		//충돌한 대상이 ground이므로, CheckOnGround를 실행합니다.
		//현재 땅 위에 있다면, 해당 땅 위에 있는 것으로 currentGround에 등록합니다.
		//Update의 Jump에서 땅 위에 있다면, 자동으로 점프를 멈춰 줍니다.
		if (CheckOnGround((Ground*)other))
		{
			currentGround = (Ground*)other;
		}
	}
}
