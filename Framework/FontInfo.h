#pragma once
#include "RenderInfo.h"
#include "Font.h"

//FontInfo�Դϴ�.
//Font�� ����ϴ� GameObject�� RenderInfo�ν� ����Ǿ�� �մϴ�.

class FontInfo :
	public RenderInfo
{
public:
	FontInfo(Font* font = nullptr);
	Font* font;

	//����� ���� text���� �����մϴ�.
	std::wstring text;

	//����� �ؽ�Ʈ�� ũ�⸦ �����մϴ�.
	//�⺻�����δ� 0.0f�� overflow�� �����Ǿ��ֽ��ϴ�. �ʿ信 ���� Font ������Ʈ�� ��Ҹ� �����Ͽ� ��� �����մϴ�.
	D2D1_RECT_F textRect;

	//RenderInfo�� Render�� ��ӹ޾� ����մϴ�.
	virtual void Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition);
	void FontRender(ID2D1RenderTarget* renderTarget, Transform* transform,  D2D1_RECT_F* sourceRect, Vector2 screenPosition);
};

