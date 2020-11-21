#pragma once
#include "stdafx.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//�浹�� ó���ϴ� Ŭ�����Դϴ�.
//�� Scene���� �� ���� ȣ��˴ϴ�.

class CollisionManager
{
public:
	//List�� ��ҵ��� �����մϴ�.
	~CollisionManager();
public:
	//������Ʈ�� ����� ����Ʈ�Դϴ�.
	std::list<GameObject*> gameObjectList;
	std::list<AABBCollider*> aabbList;
	std::list<CircleCollider*> circleList;

public:
	//����Ʈ�� �浹ü�� ����ֽ��ϴ�.
	AABBCollider* PushBackCollider(AABBCollider* col);
	CircleCollider* PushBackCollider(CircleCollider* col);

	void RemoveGameObject(GameObject* g);
public:
	//�浹 ó���� �����մϴ�.
	void Update();

public:
	//�浹 ���θ� Ȯ���մϴ�.
	//CollisionManager::Intersectedó�� static���� ��� �����մϴ�.
	static bool Intersected(AABBCollider* a, AABBCollider* b);
	static bool Intersected(CircleCollider* a, CircleCollider* b);
	static bool Intersected(AABBCollider* a, CircleCollider* b);
};

