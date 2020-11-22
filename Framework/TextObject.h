#pragma once
#include "GameObject.h"
#include "FontInfo.h"

//Text���� ����� �� ���� ���� ������Ʈ�Դϴ�.
//Font������ font Renderer�� ������ �ֽ��ϴ�.

class TextObject :
	public GameObject
{
public:
	//TextObject�� �����ϰ�, �����ڿ� ���ڿ��� �־��ָ� �ش� �ؽ�Ʈ ������ �����մϴ�.
	//���Ŀ��� textObject->fontRenderer->text ���� �����Ͽ� ���ڿ� ������ �����մϴ�.
	TextObject(const wchar_t* text);
	TextObject(std::wstring text);
	~TextObject();

	Font* font;						//�ڼ��� ������ Font.h ����
	FontInfo* fontRenderer;		//�ڼ��� ������ FontRenderer.h ����
};