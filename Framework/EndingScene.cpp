#include "stdafx.h"
#include "EndingScene.h"
#include "TextObject.h"
#include "EndToMain.h"

EndingScene::EndingScene(int score)
{
	std::wstring a = L"당신의 점수는";
	std::wstring b = L"점 입니다.";
	ment = a + std::to_wstring(score) + b;
}

EndingScene::~EndingScene()
{
}

void EndingScene::Initialize()
{
	Push(new GameObject(L"resources/background.png"));

	EndToMain* etm = new EndToMain();
	Push(etm);

	TextObject* text = new TextObject(ment);
	text->transform->SetPosition(400.0f, 300.0f);
	PushUI(text);
}
