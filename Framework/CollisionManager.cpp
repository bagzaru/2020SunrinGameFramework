#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::~CollisionManager()
{
	//Collider의 instance는 게임오브젝트에서 각자 삭제처리 해주는 것으로 간주합니다.
	aabbList.clear();
}

void CollisionManager::PushBackCollider(AABBCollider* col)
{
	aabbList.push_back(col);
	gameObjectList.push_back(col->target);
}

void CollisionManager::RemoveGameObject(GameObject* g)
{
	gameObjectList.remove(g);
	std::list<AABBCollider*>::iterator iter = aabbList.begin();
	for (; iter != aabbList.end(); iter++)
	{
		if ((*iter)->target == g)
		{
			aabbList.erase(iter);
			break;
		}
	}
}

void CollisionManager::Update()
{
	//충돌 처리
	for (std::list<AABBCollider*>::iterator i = aabbList.begin();
		i!=aabbList.end(); i++)
	{
		std::list<AABBCollider*>::iterator j = i;
		j++;
		for (; j != aabbList.end(); j++)
		{
			if(Intersected((*i),(*j)))
			{
				(*i)->target->OnCollision((*j)->target);
				(*j)->target->OnCollision((*i)->target);
			}
		}
	}
}

bool CollisionManager::Intersected(AABBCollider* a, AABBCollider* b)
{
	float aLeft, bLeft;
	float aRight, bRight;
	float aTop, bTop;
	float aBottom, bBottom;
	aLeft = a->boundingBox.leftTop.x * a->transform->scale.x
		+ a->transform->position.x;
	aRight = a->boundingBox.rightBottom.x * a->transform->scale.x
		+ a->transform->position.x;
	aTop = a->boundingBox.leftTop.y * a->transform->scale.y
		+ a->transform->position.y;
	aBottom = a->boundingBox.rightBottom.y * a->transform->scale.y
		+ a->transform->position.y;

	bLeft = b->boundingBox.leftTop.x * b->transform->scale.x
		+ b->transform->position.x;
	bRight = b->boundingBox.rightBottom.x * b->transform->scale.x
		+ b->transform->position.x;
	bTop = b->boundingBox.leftTop.y * b->transform->scale.y
		+ b->transform->position.y;
	bBottom = b->boundingBox.rightBottom.y * b->transform->scale.y
		+ b->transform->position.y;

	/*std::cout << a->boundingBox.leftTop.x << " " << a->boundingBox.rightBottom.x
		<< " " << a->boundingBox.leftTop.y << " " << a->boundingBox.rightBottom.y << "\n";
*/
	return
		!(
		(aRight < bLeft) || (bRight < aLeft) ||
			(aBottom > bTop) || (bBottom > aTop)
			);
}
	