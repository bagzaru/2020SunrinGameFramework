#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "TestScene.h"
#include "StartScene.h"

int main()
{
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new StartScene(),L"Ÿ��Ʋ", 800,600, false);
	SAFE_DELETE(f);
	//_CrtDumpMemoryLeaks();
	return 0;
}