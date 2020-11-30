#pragma once
//GameObject�� AABBCollider�� �������� �����ϴ�.
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

//Camera Ŭ�����Դϴ�.
//���ӿ�����Ʈ�� �����Ǿ�������, �� Scene���� �ѹ��� �����˴ϴ�.
//ī�޶��� ���� �� ��ġ�� �����Ͽ� �þ߸� ������ �� �ֽ��ϴ�.

class Camera :
	public GameObject
{
private:
	//ȭ���� ���μ��� �����Դϴ�.
	float screenWidth;
	float screenHeight;

	//���μ��� ����*0.5f�Դϴ�.
	float halfWidth;
	float halfHeight;

	//ȭ�� ��ü�� Collider�ν� �����մϴ�.
	AABBCollider* screenBox;
public:
	Camera();
	virtual ~Camera();	//��ӵ� ���ɼ��� �ִٸ� �Ҹ��ڸ� Virtual�� ȣ�����־�� �մϴ�.

	//ȭ�� ��ǥ<->���� ��ǥ ��ȯ �Լ����Դϴ�.
	//���� ��ǥ(World Position): x��: ������, y��: ����, ��ó�� ȭ�� �߾��� ����
	//ȭ�� ��ǥ(Screen Position): x��: ������, y��: �Ʒ���, ���� ����� ȭ���� ���� ���� ���� ����
	static Vector2 WorldPositionToScreen(const Vector2& worldPosition);
	static Vector2 ScreenPositionToWorld(const Vector2& screenPosition);

	//�ݶ��̴��� �Է¹޾� Screen ���� �ִ��� Ȯ���մϴ�.
	static bool IsOnScreen(AABBCollider* col);
	static bool IsOnScreen(CircleCollider* col);

public:
	//���� Scene�� ī�޶� �޾ƿɴϴ�.
	static Camera* GetCamera();

	//���ӿ�����Ʈ�ν� Update�մϴ�.
	void Update();
};

