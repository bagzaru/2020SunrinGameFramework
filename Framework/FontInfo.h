#pragma once
#include "RenderInfo.h"
#include "Font.h"
class FontInfo :
	public RenderInfo
{
public:
	FontInfo(Font* font = nullptr);
	Font* font;
	//wchar_t* text;
	std::wstring text;
	virtual void Render(D2DApp* d2dApp, Vector2 screenSize, Transform* transform, Vector2 cameraPosition);
	void FontRender(ID2D1RenderTarget* renderTarget, Vector2 screenSize, Transform* transform, Vector2 cameraPosition, D2D1_RECT_F* sourceRect);
};

