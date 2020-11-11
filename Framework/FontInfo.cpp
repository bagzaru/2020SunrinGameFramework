#include "stdafx.h"
#include "FontInfo.h"

FontInfo::FontInfo(Font* font)
	: RenderInfo(), font(font), text(text)
{
	textRect.left = textRect.right = textRect.bottom = textRect.top = 0.0f;
	initialized = true;
}

void FontInfo::Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition)
{
	if (!d2dApp)
	{
		printf("FontInfo::Render: d2dApp�� �����ϴ�.\n");
		return;
	}

	ID2D1HwndRenderTarget* renderTarget = d2dApp->GetRenderTarget();
	if (!renderTarget)
	{
		printf("FontInfo::Render ����, ����Ÿ���� �����ϴ�.\n");
		return;
	}
	FontRender(renderTarget, transform, nullptr, screenPosition);
}

void FontInfo::FontRender(ID2D1RenderTarget* renderTarget, Transform* transform, D2D1_RECT_F* sourceRect, Vector2 screenPosition)
{
	if (!font || !font->textFormat || !font->colorBrush)
	{
		printf("FontInfo::font ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	Vector2 screenSize;
	screenSize.x = WinApp::GetScreenWidthF();
	screenSize.y = WinApp::GetScreenHeightF();

	UINT32 len = text.length();
	   
	Point positioningCenter;
	positioningCenter.x = screenPosition.x;
	positioningCenter.y = screenPosition.y;
	//std::cout << screenPosition.x << "," << screenPosition.y << "\n";

	D2D1_RECT_F rect;
	rect.left = positioningCenter.x + textRect.left;
	rect.top = positioningCenter.y + textRect.top ;
	rect.right = positioningCenter.x +textRect.right;
	rect.bottom = positioningCenter.y + textRect.bottom;

	/*rect.left = positioningCenter.x;
	rect.top = positioningCenter.y;
	rect.right = positioningCenter.x;
	rect.bottom = positioningCenter.y;*/
	//std::cout << rect.left << "," << rect.right << ","<<rect.top<<","<<rect.bottom<<"\n";

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
	//UINT32 len = wcslen(text);	//WCHAR ���ڿ� �� ���
	/*renderTarget->DrawTextW(text.c_str(), len, font->textFormat,
		D2D1::RectF(positioningCenter.x, positioningCenter.y, positioningCenter.x + 640.0f, positioningCenter.y + 415.0f),
		font->colorBrush);*/
	renderTarget->DrawTextW(text.c_str(), len, font->textFormat,
		rect,
		font->colorBrush); 
}
