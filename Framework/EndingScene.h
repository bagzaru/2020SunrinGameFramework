#pragma once
#include "Scene.h"

//���� ��� ���� ������ ��Ÿ���ϴ�.

class EndingScene :
	public Scene
{
public:
	std::wstring ment;

	//�����ڷμ� ���� Scene���� ���� ���� �޾ƿɴϴ�.
	//������ �̿��� Scene�� �ʱ�ȭ�Ǳ� ���� ȣ��ǹǷ�, ������ ��� �� �޾ƿ��� ����� ����� �����մϴ�.
	EndingScene(int score);
	~EndingScene();

	//�ʱ�ȭ �Լ�
	void Initialize();
};

