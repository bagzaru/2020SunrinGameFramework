#include "stdafx.h"
#include "ScoreManager.h"

ScoreManager* ScoreManager::instance;

ScoreManager::ScoreManager()
	:GameObject(fontRenderer = new FontInfo()), score(0)
{
	font = new Font(L"±Ã¼­", 20.0f, 1.0f, 1.0f, 1.0f, 1.0f, false);
	fontRenderer->font = this->font;
	fontRenderer->text = L"Score: " + std::to_wstring(score);
	
	transform->SetPosition(WinApp::GetScreenWidthF()*0.5f,10.0f);

	instance = this;
}

ScoreManager::~ScoreManager()
{
	SAFE_DELETE(font);
	instance = nullptr;
}

void ScoreManager::UpdateScore()
{
	fontRenderer->font->GetFontStretch();
	instance->fontRenderer->text = L"Score: " + std::to_wstring(instance->score);
}

void ScoreManager::AddScore(int value)
{
	instance->score += value;
	instance->UpdateScore();
}
