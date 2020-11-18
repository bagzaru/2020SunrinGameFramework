#pragma once
#include "Scene.h"
class EndingScene :
	public Scene
{
public:
	std::wstring ment;
	EndingScene(int score);
	~EndingScene();
	void Initialize();
};

