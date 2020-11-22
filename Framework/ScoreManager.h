#pragma once
#include "GameObject.h"
#include "FontInfo.h"

//���� ó���� �����ϴ� ��ü�Դϴ�.
//�⺻������ text�� ����ϴ� ��ü�Դϴ�. (FontInfo���)
//�̱��� ������ Ȱ���Ͽ� �ٸ� ��� ��ü���� ������ �����մϴ�. �̱����� ���۸��Ͻðų� ������ ���� �ּ���.
//�� ������ ������ �����ϰ�, �� ���� �ؽ�Ʈ�� ������Ʈ �մϴ�.

class ScoreManager :
	public GameObject
{
public:
	Font* font;
	FontInfo* fontRenderer;
	int score;

public:
	ScoreManager();
	~ScoreManager();

	void UpdateScore();

public:
	static ScoreManager* instance;
	static void AddScore(int value);
};

