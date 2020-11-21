#pragma once
//������� ��Ÿ���� InputManagerŬ���� �Դϴ�.

//WinApp�� ����մϴ�.
#include "WinApp.h"

//Ű�� ������ �ִ� ��츦 2, ���� ��츦 1, ������ ��츦 -1�� ó���մϴ�.
//�ε�ȣ�� ��ȣ�� �̿��Ͽ� ����� �����մϴ�.
//true, falseó�� 0�� �ƴϸ� ���� ������ �͵� üũ �����մϴ�.
#define KEYPRESSED 2
#define KEYDOWN 1
#define KEYUP -1


//�Է��� ����ϴ� InputManager Ŭ�����Դϴ�.
//Framework Ŭ�������� ȣ��˴ϴ�.
class InputManager
{
	friend class Framework;				
public:
	InputManager();
	~InputManager();
private:
	//WinApp�� ����մϴ�.
	static WinApp* winApp;			

	//������ �Էµ� ���� ���� �Էµ� ���� �����մϴ�.
	//�ش� ������ ���Ͽ� Ű�� ���¸� Ȯ���մϴ�.
	static bool lkey[256], rkey[256];

	//���콺�� ��ġ�� int�� �����մϴ�.
	static int mX, mY;

public:
	//�� ������ ȣ��Ǿ� Ű�� ���¸� Update�մϴ�.
	static void UpdateKeyState();

	//���� ���� �� Ű �Է��� ����� �� ���Ǵ� �Լ����Դϴ�.
	static int GetKeyState(int vk);	//Ű�� ���¸� ���ڷ� ��ȯ�մϴ�.
	static bool GetKeyDown(int vk);	//Ű�� �� ���� ���������� Ȯ���մϴ�.
	static bool GetKeyPressed(int vk);	//Ű�� ������ �ִ����� Ȯ���մϴ�.
	static bool GetKeyUp(int vk);	//Ű�� �� ������ �������� Ȯ���մϴ�.

public:
	//���콺�� ��ġ�� Ȯ���մϴ�.
	static int GetMouseX();
	static int GetMouseY();
};

