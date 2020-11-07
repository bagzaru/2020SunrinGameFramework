#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
private:
	Transform* transform;
public:
	float left;
	float right;
	float top;
	float bottom;

	bool Intersected(AABBCollider* col);

	AABBCollider(GameObject* target, float left, float right, float top, float bottom);
	~AABBCollider();
};

