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
	//�켱 ����� �Ʒ��κа� ���� ���κ��� ���մϴ�.
	//GetTransformedBox(): position ��ġ�� ����� ���ڸ� ���մϴ�.
	Collider::AABBBox myBox = col->GetTransformedBox();
	float foot = g->GetTransformedBox().rightBottom.y;
	float surface = myBox.leftTop.y;

	//������Ʈ�� �� �κа� ���� �� �κ� ������ �Ÿ��� gap �̳��� ���, ���� �� �κ����� �ö�Դ� �����մϴ�.
	//��, �쵵 ���ƴ��� Ȯ���մϴ�.
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
