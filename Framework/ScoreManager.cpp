#include "stdafx.h"
#include "ScoreManager.h"

//���� �����ν� �̱��� ���Ͽ� ���˴ϴ�.
//�̱��� ������ ���۸��Ͻðų� ������ ���� �ּ���.
ScoreManager* ScoreManager::instance;

//���� ������ �ʱ�ȭ�մϴ�.
//�ؽ�Ʈ�� �������ϴ� ��ü�̹Ƿ�, Renderer�� FontInfo�� ����մϴ�.
ScoreManager::ScoreManager()
	:GameObject(fontRenderer = new FontInfo()), score(0)
{
	//font ������ �ʱ�ȭ�մϴ�.
	font = new Font(L"�ü�", 20.0f, 1.0f, 1.0f, 1.0f, 1.0f, false);
	fontRenderer->font = this->font;
	fontRenderer->text = L"Score: " + std::to_wstring(score);
	
	transform->SetPosition(WinApp::GetScreenWidthF()*0.5f,10.0f);

	instance = this;
}

ScoreManager::~ScoreManager()
{
	//font ��� �Ŀ��� �ʱ�ȭ ���־�� �մϴ�.
	SAFE_DELETE(font);
	instance = nullptr;
}

void ScoreManager::UpdateScore()
{
	//score���� ���� text�� ������Ʈ�մϴ�.
	instance->fontRenderer->text = L"Score: " + std::to_wstring(instance->score);
}

//�̱��� ��ü�� ������ �߰��մϴ�.
void ScoreManager::AddScore(int value)
{
	instance->score += value;
	instance->UpdateScore();
}
