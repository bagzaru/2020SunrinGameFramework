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
	//우선 대상의 아랫부분과 땅의 윗부분을 구합니다.
	//GetTransformedBox(): position 위치를 계산한 상자를 구합니다.
	float foot = g->boundingBox.rightBottom.y * g->transform->scale.y + g->transform->position.y;
	float surface = col->boundingBox.leftTop.y * transform->scale.y + transform->position.y;
	
	//오브젝트의 발 부분과 땅의 윗 부분 사이의 거리가 gap 이내일 경우, 나의 윗 부분으로 올라왔다 판정합니다.
	//위, 아래만 판정합니다.
	if (foot - deltaSpeed - surface > -gap && foot - surface < gap)
	{
		return true;
	}
	else
	{
		return false;
	}
}
