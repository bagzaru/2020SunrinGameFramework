#pragma once
#include "WinApp.h"
#include "D2DApp.h"
#include "Scene.h"

//������ ��� ���� ��Ÿ���� Framework�Դϴ�.
//���� ���̺귯���� �ʱ�ȭ�ϰ�, ���� ������ �����ϴ�.
class Framework
{
public:
	Framework();
	~Framework();
private:
	WinApp* winApp;
	D2DApp* d2dApp;

public:
	//main �Լ����� ȣ��Ǵ� �Լ��Դϴ�.
	void Run(Scene* startScene,const wchar_t* title, int width, int height, bool isFullScreen);

private:
	//���� ������ �����մϴ�.
	void StartGameLoop();
};
