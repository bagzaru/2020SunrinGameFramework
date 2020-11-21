#pragma once
#include "Component.h"
#include "Vector2.h"

//���� ������Ʈ�� ���� ������ �����մϴ�.
//��ġ����, ȸ������, ũ�� ������ �����մϴ�.
//(position, rotation, scale)
class Transform :
	public Component
{
public:
	Transform(Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	virtual ~Transform();

public:
	//�����δ� ������ �ʴ� �Լ��Դϴ�.
	virtual void Update() {};

	//��ġ ,ȸ�� ,ũ��
	Vector2 position;			//��ġ���� (x,y)
	float rotatingAngle;	//ȸ�� ����
	Vector2 scale;			//ũ��

	//�� ��ȯ�� ���� �������Դϴ�.
	Vector2 positioningCenter;	//��ġ ���� ����(�⺻ ���� �̹��� �����)
	Vector2 rotatingCenter;		//ȸ����
	Vector2 scalingCenter;		//ũ�� ��ȯ��

public:
	//Setter �Լ�
	void SetPosition(float x, float y);
	void SetPosition(const Vector2& v);
	void SetRotation(float angle);
	void SetScale(float x, float y);
	void SetScale(const Vector2& v);
};

