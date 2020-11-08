#include "stdafx.h"
#include "AABBCollider.h"


AABBCollider::AABBCollider(GameObject* target,
	float left, float bottom, float right, float top)
{
	this->target = target;
	this->left	= left;
	this->right = right;
	this->top	= top;
	this->bottom = bottom;
	this->transform = target->transform;
}

bool AABBCollider::Intersected(AABBCollider* other)
{
	float aLeft, bLeft;
	float aRight, bRight;
	float aTop, bTop;
	float aBottom, bBottom;
	aLeft = left * transform->scale.x
		+ transform->position.x;
	aRight = right * transform->scale.x
		+ transform->position.x;
	aTop = top * transform->scale.y
		+ transform->position.y;
	aBottom = bottom * transform->scale.y
		+ transform->position.y;
	bLeft = other->left * other->transform->scale.x
		+ other->transform->position.x;
	bRight = other->right * other->transform->scale.x
		+ other->transform->position.x;
	bTop = other->top * other->transform->scale.y
		+ other->transform->position.y;
	bBottom = other->bottom * other->transform->scale.y
		+ other->transform->position.y;

	return
		!(
		(aRight < bLeft) || (bRight < aLeft) ||
			(aBottom > bTop) || (bBottom > aTop)
			);
}


AABBCollider::~AABBCollider()
{
}
