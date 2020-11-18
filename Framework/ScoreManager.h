#pragma once
#include "GameObject.h"
#include "FontInfo.h"
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

