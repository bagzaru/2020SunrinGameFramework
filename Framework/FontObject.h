#pragma once
#include "GameObject.h"
#include "FontInfo.h"

//��Ʈ�� ����ϴ� ������Ʈ�� ���� ������Ʈ �Դϴ�.
//���� ������Ʈ����, ���� ���ӿ����� TextObject ����� �����մϴ�.

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

