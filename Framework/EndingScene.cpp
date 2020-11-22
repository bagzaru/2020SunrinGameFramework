#include "stdafx.h"
#include "EndingScene.h"
#include "TextObject.h"
#include "EndToMain.h"

//�������Դϴ�.
//score ���� �޾ƿ� ��, ������ ����Ͽ� ment ���ڿ��� �־�Ӵϴ�.
//�� �� ���� Scene�� ���۵� ��, TextObject�� �߰��Ͽ� ����մϴ�.
EndingScene::EndingScene(int score)
{
	std::wstring a = L"����� ������";
	std::wstring b = L"�� �Դϴ�.";
	ment = a + std::to_wstring(score) + b;
}

EndingScene::~EndingScene()
{
}

void EndingScene::Initialize()
{
	//background�� �߰��մϴ�.
	Push(new GameObject(L"resources/background.png"));

	//���� Scene���� Esc�� ������ �������� ���ư��� ������ ������ ��ü�Դϴ�.
	EndToMain* etm = new EndToMain();
	Push(etm);

	//������ ��Ʈ�� ����ϴ� ��ü�Դϴ�.
	TextObject* text = new TextObject(ment);
	text->transform->SetPosition(400.0f, 300.0f);
	PushUI(text);
}
