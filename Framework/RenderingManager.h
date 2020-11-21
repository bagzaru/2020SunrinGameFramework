#pragma once
#include "stdafx.h"
#include "D2DApp.h"
#include "RenderInfo.h"

//�������� �����ϴ� Ŭ�����Դϴ�.
//�� Scene�� �ϳ��� �����˴ϴ�.
//D2DApp�� RenderInfo(Renderer)���� ����â�� ������ �մϴ�.

class RenderingManager
{
private:
	//D2DApp Ŭ������ �޾ƿɴϴ�.
	D2DApp* d2dApp;

	//ȭ�� ũ�⸦ �����մϴ�.
	Vector2 screenSize;

public:
	RenderingManager(D2DApp* d2dApp);
	~RenderingManager();

public:
	//Scene���� ����� Sprite�� �� ���� ��� �����մϴ�.
	//���� Sprite�� Load�� ��� �� ����Ʈ�� �̹� Sprite�� �ִٸ� �� Sprite�� ����մϴ�.
	std::list<Sprite*> spriteList;

	//png, jpg, bmp, gif ���� ������ �ε��մϴ�.
	//Direct2D���� ����ϱ� ���Ͽ� ��Ʈ�� �������� ��ȯ�Ͽ� ����˴ϴ�.
	Sprite* LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight);

	//Font�� ����ϱ� ���� �Լ��Դϴ�.
	//Font ��ü ������ ����մϴ�.
	IDWriteTextFormat* CreateTextFormat(const WCHAR* fontFamilyName, IDWriteFontCollection* fontCollection, DWRITE_FONT_WEIGHT fontWeight, DWRITE_FONT_STYLE fontStyle, DWRITE_FONT_STRETCH fontStretch, FLOAT fontSize, const WCHAR* localeName);
	ID2D1SolidColorBrush* CreateSolidColorBrush(const D2D1_COLOR_F& color);

	//Scene->Render���� ����մϴ�.
	//Render�� ���۰� ���� ȣ��˴ϴ�.
	void BeginRender();
	void EndRender();	
};

