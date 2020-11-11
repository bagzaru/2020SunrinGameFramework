#include "stdafx.h"
#include "FontObject.h"
#include "TimeManager.h"

FontObject::FontObject()
	:GameObject(fontRenderer = new FontInfo())
{
	ws = L"���� ������.";
	timer = 0.0f;
	font = new Font(L"����",20.0f,1.0f,1.0f,1.0f);						//��Ʈ, ���� ���� ���ϴ� Font Ŭ���� ����(Font.h ����), �⺻ ũ�� 20pt
	fontRenderer->font = this->font;				//�ؽ�Ʈ�� �Ӽ��� �������ݴϴ�.

	fontRenderer->text = ws;						//�ؽ�Ʈ�� ������ �������ݴϴ�.
	transform->SetPosition(0.0f,0.0f);			//��ġ ����
	//transform->SetRotation(30.0f);					//���� ����
	transform->SetScale(1.0f, 1.0f);				//ũ�� ���� ��� �����մϴ�.
}

FontObject::~FontObject()
{
	SAFE_DELETE(font);
}

void FontObject::Update()
{
	timer += TimeManager::GetDeltaTime();
	if (timer > 3.0f)
	{
		fontRenderer->font->UpdateFontStyle(L"�ü�",18.0f,1.0f,0.0f,0.0f,0.5f,true);
		fontRenderer->text = L"EnterŰ�� ������ �Ѿ�ϴ�.\n�ƴϸ� ���⸦ Ŭ���ϼ���.";
		std::wcout << fontRenderer->text;
	}
}
