#include "stdafx.h"
#include "SubCamera.h"

SubCamera::SubCamera(Vector2 subScreenSize, D2DApp* d2dApp)
	:GameObject(subRenderer = new RenderInfo()), 
	subRenderTarget(subRenderTarget), d2dApp(d2dApp)
{
	subScreenSprite = new Sprite();
	subRenderTarget = d2dApp->CreateSubRenderTarget(subScreenSize.x, subScreenSize.y);
	subRenderTarget->GetBitmap(&subScreenSprite->bitmap);
	D2D1_SIZE_F s = subRenderTarget->GetSize();
	this->subScreenSize.x = s.width;
	this->subScreenSize.y = s.height;

	subRenderer->currentSprite = subScreenSprite;
	subRenderer->initialized = true;
	subRenderer->width = s.width;
	subRenderer->height = s.height;
}

SubCamera::~SubCamera()
{
	SAFE_RELEASE(subRenderTarget);
	SAFE_RELEASE(subScreenSprite->bitmap);
	SAFE_DELETE(subScreenSprite);
}

void SubCamera::Update()
{
}

void SubCamera::BeginSubRender()
{
	//반드시 EndSubRender도 호출해야함
	subRenderTarget->BeginDraw();
	subRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	subRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));
}

void SubCamera::EndSubRender()
{
	subRenderTarget->EndDraw();
}