#pragma once
#include "GameObject.h"
#include "FontInfo.h"
class FontObject :
	public GameObject
{
public:
	FontObject();
	~FontObject();

	void Update();

	float timer;

	Font* font;						//�ڼ��� ������ Font.h ����
	FontInfo* fontRenderer;		//�ڼ��� ������ FontRenderer.h ����
	std::wstring ws;
};

