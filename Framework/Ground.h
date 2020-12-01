#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Ground :
	public GameObject
{
public:
	Ground(const wchar_t* uri);
	~Ground();

	//땅의 충돌체
	AABBCollider* col;

	//발판과 바닥 사이 거리가 gap 이내일 경우 올라온 것으로 판정. 
	float gap;		

	//대상이 땅 위에 있는지 체크함.
	bool CheckStand(AABBCollider* g, float speed);
};

