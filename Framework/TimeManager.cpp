#include "stdafx.h"
#include "TimeManager.h"

TimeManager::TimeManager(){}
TimeManager::~TimeManager(){}

float TimeManager::deltaTime;

//DeltaTime�� �� ������ ������ݴϴ�.
//Framework�� MainLoop���� �� ������ ȣ��˴ϴ�.
//���� �ð� - ���� �������� �ð��� ����Ͽ� DeltaTime�� ����մϴ�.
void TimeManager::UpdateTime()
{
	static DWORD oldTime = timeGetTime();

	DWORD curTime = timeGetTime();
	deltaTime = (float)(curTime - oldTime)*0.001f;
	oldTime = curTime;
}

//static �Լ��Դϴ�. ����� Delta Time�� �ҷ��ɴϴ�.
float TimeManager::GetDeltaTime()
{//getter�Լ�
	return deltaTime;
}
