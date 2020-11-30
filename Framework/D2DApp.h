#pragma once
#include "stdafx.h"
#include "WinApp.h"

//DirectX ��ü�Դϴ�.

struct Sprite {
	const wchar_t* uri;
	ID2D1Bitmap* bitmap;
};

class D2DApp
{
public:
	D2DApp(WinApp* winApp);
private:
	WinApp* winApp;

public:
	//�ʱ�ȭ, ������ ����ϴ� �Լ��Դϴ�.
	bool Initialize();
	void Uninitialize();

private:
	//Direct2D���� ����� ���� �ڿ��� �����մϴ�.
	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceResources();
	void DiscardDeviceResources();
	void DiscardDeviceIndependentResources();

public:
	//�׽�Ʈ�� �Լ��Դϴ�.
	ID2D1Bitmap* example;
	void Render();

	//������ ����, ���� ȣ���ϴ� �Լ��Դϴ�.
	void BeginRender();
	void EndRender();

	//��Ʈ���� �ε��մϴ�. RenderingManager������ ����մϴ�.
	HRESULT LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap** bitmap);

private:
	//Direct2D �ڿ� ��ü���Դϴ�.
	ID2D1Factory* factory;
	IWICImagingFactory* wicFactory;
	ID2D1HwndRenderTarget* renderTarget;
	IDWriteFactory* dwriteFactory;

	
	
	
public:
	ID2D1HwndRenderTarget* GetRenderTarget();
	IWICImagingFactory* GetImagingFactory();
	ID2D1Factory* GetFactory();
	IDWriteFactory* GetDwriteFactory();

public:
	ID2D1BitmapRenderTarget* CreateSubRenderTarget(float width, float height);
};

