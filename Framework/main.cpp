#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"
#include "StartScene.h"

//�⺻ ���� �Լ��Դϴ�.

int main()
{
	//�����ӿ�ũ ��ü�� �����ϴ� ��ü�Դϴ�.
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new StartScene(),L"Ÿ��Ʋ", 800,600, false);
	SAFE_DELETE(f);

	//�޸� ������ Ȯ���� �� ����մϴ�. stdafx.h�� �����ϼ���.
	//_CrtDumpMemoryLeaks();
	return 0;
}