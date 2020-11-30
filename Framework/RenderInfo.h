#pragma once
#include "D2DApp.h"
#include "Component.h"
#include "Transform.h"

//Render ������ �����մϴ�.
//���� �̸��� Renderer�����ϴ�. Renderer�� �� �� ��︮�� �̸� �����ϴ�.
//Render�� ���� ������ �����ϰ�, Render�մϴ�.

//�⺻������ Sprite ������ ����������, �ʿ信 ���� ��ӹ޾� ����� �� �ֽ��ϴ�.
//currentSprite�� ����� ��������Ʈ�� ��µ˴ϴ�.
//Ȥ�� Render�Լ��� ��ӹ޾� ������ ���ֽ��ϴ�.
//AnimationRenderInfo, FontRenderInfo ���� �ڽ� Ŭ������ �����մϴ�.

class RenderInfo :
	public Component
{
public:
	RenderInfo();
	RenderInfo(Sprite* startSprite, float alpha = 1.0f);
	virtual ~RenderInfo() {}
public:
	//���� ����� Sprite�� �����մϴ�.
	Sprite* currentSprite;

	//�ʱ�ȭ�Ǿ������� �����մϴ�.
	//�̹����� ��Ʈ ���� �ε��� �� true�� �ٲ���� ����� �����մϴ�.
	bool initialized;

	//�⺻ �̹����� ����, ���θ� �����մϴ�.
	int width, height;

public:
	//������ �����մϴ�.
	float alpha;

public:
	//Getter �Լ�
	Sprite* GetCurrentSprite();
	float GetAlpha();

	bool GetInitialized();
	virtual int GetWidth();
	virtual int GetHeight();

	virtual D2D1_RECT_F* GetSourceRect();

	//Update�Դϴ�. ��� �� ������� �ʽ��ϴ�.
	virtual void Update() {}

	//RenderInfo�� Render�ø��� ȣ���Ͽ� ����մϴ�.
	//�ִϸ��̼��� ������ ������Ʈ � ���˴ϴ�.
	virtual void UpdateRenderInfo() {}

	//RenderingManager Ŭ�������� ���� Render�� ������ �� ���Ǵ� �Լ��Դϴ�.
	virtual void Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition);

	//Sprite�� �����մϴ�.
	void BasicRender(ID2D1RenderTarget* renderTarget, Transform* transform, D2D1_RECT_F* sourceRect, Vector2 screenPosition);
	
	//Render�� ���� ���� �Լ��Դϴ�.
	//Transform�� �����մϴ�.
	Vector2 ComputeWorldPosition(Vector2 screenSize, Transform* transform, Vector2 cameraPosition);
	Vector2 ComputeUIPosition(Transform* transform);
};

