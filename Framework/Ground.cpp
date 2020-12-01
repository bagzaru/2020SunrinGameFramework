#include "stdafx.h"
#include "Ground.h"
#include "TimeManager.h"
#include "Scene.h"

Ground::Ground(const wchar_t* uri)
	:GameObject(uri), gap(20.0f)
{
	tag = Tag::Ground;
	col = new AABBCollider(this, renderer);
	Scene::PushOnCurrentScene(col);
}

Ground::~Ground()
{
	SAFE_DELETE(col);
}

bool Ground::CheckStand(AABBCollider* g, float deltaSpeed)
{
	//�켱 ����� �Ʒ��κа� ���� ���κ��� ���մϴ�.
	//GetTransformedBox(): position ��ġ�� ����� ���ڸ� ���մϴ�.
	float foot = g->boundingBox.rightBottom.y * g->transform->scale.y + g->transform->position.y;
	float surface = col->boundingBox.leftTop.y * transform->scale.y + transform->position.y;
	
	//������Ʈ�� �� �κа� ���� �� �κ� ������ �Ÿ��� gap �̳��� ���, ���� �� �κ����� �ö�Դ� �����մϴ�.
	//��, �Ʒ��� �����մϴ�.
	if (foot - deltaSpeed - surface > -gap && foot - surface < gap)
	{
		return true;
	}
	else
	{
		return false;
	}
}
