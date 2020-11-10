#include "stdafx.h"
#include "FontInfo.h"

FontInfo::FontInfo(Font* font)
	: font(font), text(text)
{
	initialized = true;
}

void FontInfo::Render(D2DApp* d2dApp, Vector2 screenSize, Transform* transform, Vector2 cameraPosition)
{

	if (!d2dApp)
	{
		printf("FontInfo::Render: d2dApp이 없습니다.\n");
		return;
	}

	ID2D1HwndRenderTarget* renderTarget = d2dApp->GetRenderTarget();
	if (!renderTarget)
	{
		printf("FontInfo::Render 실패, 렌더타겟이 없습니다.\n");
		return;
	}
	FontRender(renderTarget, screenSize, transform, cameraPosition, nullptr);
}

void FontInfo::FontRender(ID2D1RenderTarget* renderTarget, Vector2 screenSize, Transform* transform, Vector2 cameraPosition, D2D1_RECT_F* sourceRect)
{
	if (!font || !font->textFormat || !font->colorBrush)
	{
		printf("FontInfo::font 정보가 존재하지 않습니다.\n");
		return;
	}

	Point positioningCenter;
	positioningCenter.x = transform->position.x - transform->positioningCenter.x;
	positioningCenter.y = transform->position.y - transform->positioningCenter.y;

	D2D1_RECT_F rect;
	rect.left = positioningCenter.x - screenSize.x * 0.5f;
	rect.top = positioningCenter.y - screenSize.y * 0.5f;
	rect.right = positioningCenter.x + screenSize.x * 0.5f;
	rect.bottom = positioningCenter.y + screenSize.y * 0.5f;

	Point scalingCenter;
	scalingCenter.x = positioningCenter.x + transform->scalingCenter.x;
	scalingCenter.y = positioningCenter.y + transform->scalingCenter.y;

	Point rotatingCenter;
	rotatingCenter.x = positioningCenter.x + transform->rotatingCenter.x;
	rotatingCenter.y = positioningCenter.y + transform->rotatingCenter.y;

	renderTarget->SetTransform(
		D2D1::Matrix3x2F::Scale(
			transform->scale.x,
			transform->scale.y,
			scalingCenter)
		* D2D1::Matrix3x2F::Rotation(
			transform->rotatingAngle,
			rotatingCenter
		));
	//UINT32 len = wcslen(text);	//WCHAR 문자열 쓸 경우
	UINT32 len = text.length();
	renderTarget->DrawTextW(text.c_str(), len, font->textFormat,
		D2D1::RectF(positioningCenter.x, positioningCenter.y, positioningCenter.x + 640.0f, positioningCenter.y + 415.0f),
		font->colorBrush);


}
