#pragma once
#include "Transform.h"
#include "GameObject.h"
class Collider
{
public:
	struct AABBBox //AABB �浹ó��
	{
		Vector2 leftTop;			//(0,0)�� �������� �� �»�� �������� �����ǰ��Դϴ�. ������ �߽��� 0,0���� �ξ��� ��� ���� ���� ������ �˴ϴ�.
		Vector2 rightBottom;		//(0,0)�� �������� �� ���ϴ� �������� �����ǰ��Դϴ�. ������ �߽��� 0,0���� �ξ��� ��� ��� ���� ������ �˴ϴ�.

		AABBBox();
		AABBBox(const AABBBox& box);
		AABBBox(const Vector2& size);
		AABBBox(float width, float height);
		AABBBox(const Vector2& leftTop, const Vector2& rightBottom);
		AABBBox(float left, float top, float right, float bottom);
	};
	struct Circle //center���� transform.position�� ���������� �Ÿ��Դϴ�.
	{
		Vector2 center;			//�⺻������ 0,0
		float radius;			//���� ������

		Circle();
		Circle(const Circle& circle);
		Circle(float radius);
		Circle(const Vector2& center, float radius);
		Circle(float x, float y, float radius);
	};
public:
	Collider(GameObject* target);
public:
	GameObject* target;
	Transform* transform;
};

