#pragma once
#include "Button.h"
class ExitButton :
	public Button
{
public:
	ExitButton(const wchar_t* uri);
	void OnClick();
};

