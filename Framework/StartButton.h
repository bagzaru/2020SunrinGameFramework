#pragma once
#include "Button.h"

//��ŸƮ ��ư�Դϴ�.
//Button�̶�� Ŭ������ ��ӹ޽��ϴ�.
//Framework�� ��ü ������ Ŭ������ �ƴϰ�, �ٷ� StartScene ���� ���� ������� �ֽ��ϴ�.
class StartButton :
	public Button
{
public:
	StartButton(const wchar_t* uri);
	void OnClick();
};

