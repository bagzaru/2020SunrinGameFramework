#pragma once
#include "Camera.h"
class SubCamera :
	public GameObject
{
public:
	ID2D1BitmapRenderTarget* subRenderTarget;
	D2DApp* d2dApp;
	RenderInfo* subRenderer;
	Vector2 subScreenSize;
	Sprite* subScreenSprite;

	Vector2 lookAtPosition;

	SubCamera(Vector2 subScreenSize, D2DApp* d2dApp);
	~SubCamera();

	void BeginSubRender();
	void EndSubRender();
	
	void Update();
};

