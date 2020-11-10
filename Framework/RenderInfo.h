#pragma once
#include "D2DApp.h"
#include "Component.h"
#include "Transform.h"


class RenderInfo :
	public Component
{
public:
	RenderInfo();
	RenderInfo(Sprite* startSprite, float alpha = 1.0f);
	virtual ~RenderInfo() {}
protected:
	Sprite* currentSprite;
	float alpha;
	bool initialized;
	int width, height;

public:
	Sprite* GetCurrentSprite();
	float GetAlpha();
	bool GetInitialized();
	virtual int GetWidth();
	virtual int GetHeight();
	virtual D2D1_RECT_F* GetSourceRect();
	virtual void Update() {}
	virtual void UpdateRenderInfo() {}
	virtual void Render(D2DApp* d2dApp, Vector2 screenSize, Transform* transform, Vector2 cameraPosition);
	void BasicRender(ID2D1RenderTarget* renderTarget, Vector2 screenSize, Transform* transform, Vector2 cameraPosition, D2D1_RECT_F* sourceRect);
};

