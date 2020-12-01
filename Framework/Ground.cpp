#include "stdafx.h"
#include "Ground.h"

Ground::Ground(const wchar_t* uri)
	:GameObject(uri), gap(20.0f)
{
}

Ground::~Ground()
{
	SAFE_DELETE(col);
}

bool Ground::CheckStand(AABBCollider* g, float speed)
{
	//우선 대상의 아랫부분과 땅의 윗부분을 구합니다.
	//GetTransformedBox(): position 위치를 계산한 상자를 구합니다.
	Collider::AABBBox myBox = col->GetTransformedBox();
	float foot = g->GetTransformedBox().rightBottom.y;
	float surface = myBox.leftTop.y;

	//오브젝트의 발 부분과 땅의 윗 부분 사이의 거리가 gap 이내일 경우, 나의 윗 부분으로 올라왔다 판정합니다.
	//좌, 우도 겹쳤는지 확인합니다.
	if (foot - surface > -gap && foot - surface < gap &&
		g->transform->position.x > transform->position.x + myBox.leftTop.x &&
		g->transform->position.x < transform->position.x - myBox.rightBottom.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}
