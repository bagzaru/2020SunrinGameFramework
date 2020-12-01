#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Ground :
	public GameObject
{
public:
	Ground(const wchar_t* uri);
	~Ground();

	//���� �浹ü
	AABBCollider* col;

	//���ǰ� �ٴ� ���� �Ÿ��� gap �̳��� ��� �ö�� ������ ����. 
	float gap;		

	//����� �� ���� �ִ��� üũ��.
	bool CheckStand(AABBCollider* g, float speed);
};

