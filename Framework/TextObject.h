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

	Font* font;						//�ڼ��� ������ Font.h ����
	FontInfo* fontRenderer;		//�ڼ��� ������ FontRenderer.h ����
};

