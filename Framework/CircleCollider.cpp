#include "stdafx.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(GameObject* gameObject, const Circle& circle)
	:Collider(gameObject), boundingCircle(circle)
{
}

CircleCollider::CircleCollider(GameObject* gameObject, float radius, const Vector2& center)
	: Collider(gameObject), boundingCircle(center, radius)
{
}

CircleCollider::CircleCollider(GameObject* gameObject, float x, float y, float radius)
	: Collider(gameObject), boundingCircle(x, y, radius)
{
}

Collider::Circle CircleCollider::GetTransformedCircle()
{
	return Circle(boundingCircle.center + transform->position, boundingCircle.radius);
}
