#pragma once
#include "GameObject.h"
#include "FontInfo.h"
class TextObject :
	public GameObject
{
public:
	TextObject(const wchar_t* text);
	TextObject(std::wstring text);
	~TextObject();

	Font* font;						//자세한 설명은 Font.h 참고
	FontInfo* fontRenderer;		//자세한 설명은 FontRenderer.h 참고
};

