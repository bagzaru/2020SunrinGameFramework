#pragma once
#include "Button.h"


//����Ʈ ��ư�Դϴ�.
//Button�̶�� Ŭ������ ��ӹ޽��ϴ�.
//Framework�� ��ü ������ Ŭ������ �ƴϰ�, �ٷ� StartScene ���� ���� ������� �ֽ��ϴ�.
class ExitButton :
	public Button
{
public:
	ExitButton(const wchar_t* uri);
	void OnClick();
};

