#pragma once
#include "Camera.h"
class SubScreen :
	public GameObject
{
public:
	ID2D1BitmapRenderTarget* subRenderTarget;
	D2DApp* d2dApp;
	RenderInfo* subRenderer;
	Vector2 subScreenSize;
	Sprite* subScreenSprite;

	Vector2 lookAtPosition;

	Transform* target;

	SubScreen(Vector2 subScreenSize, D2DApp* d2dApp);
	~SubScreen();

	void BeginSubRender();
	void EndSubRender();
	
	void Update();
};

