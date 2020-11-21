#pragma once
//stdafx.h �̸� �����ϵ� ��� �����Դϴ�.
//�̸� �����ϵ� ���: ���� ����ϴ� ��� ������ �̸� �������Ͽ� �����ϰ�, ���� ������ �ӵ��� �÷��ݴϴ�.
//�� �ܿ��� ��� cpp ���Ͽ��� ����� ����� ��� �����ϴ� ������ �ֽ��ϴ�.
//���� ���� ��� ���ϰ� ���̺귯�� ������ ���⼭ ��Ŭ��� �մϴ�.

//Windows.h, ������ â�� ���� �⺻ �Լ��� ����ϱ� ���� ��� �����Դϴ�.
#include <Windows.h>

//C++ �⺻ ��� �����Դϴ�.
#include <iostream>		//�����(�ܼ� ��)
#include <string>		//���ڿ�
#include <list>			//����Ʈ
#include <vector>		//����
#include <random>		//����

//���̷�ƮX ���� ��� �����Դϴ�.
#include <d2d1.h>
#include <d2d1helper.h>

//COM ������Ʈ�� ����ϱ� ���� ��������Դϴ�.
#include <wincodec.h>

//FONT�� ����ϱ� ���� DirectWrite ��������Դϴ�.
#include <dwrite.h>

//SOUND�� ����ϱ� ���� Xaudio2, MF���� ��������Դϴ�.
#include <xaudio2.h>
#include <mfapi.h>		//wmf
#include <mfidl.h>
#include <mfreadwrite.h>

//�޸� ���� üũ�� ��������Դϴ�.
//����� ��忡�� �Ʒ� CheckMemoryLeak.h�� �ּ��� �����ϸ� ��� �����մϴ�.
//main �Լ� �������� _CrtDumpMemoryLeaks(); �߰����ָ� ����� �� ��� â�� ������ �޸𸮸� Ȯ���� �� �ֽ��ϴ�.
//#include "CheckMemoryLeak.h"


//�Ʒ��� ���̺귯���� �����ϱ� ���� �ڵ��Դϴ�.

//���̷�ƮX, ������ ���� ���̺귯��
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "WindowsCodecs.lib")
#pragma comment(lib, "Winmm.lib")

//Font: DirectWrite ���̺귯��
#pragma comment(lib, "Dwrite.lib")

//SOUND: Xaudio2, MF ���̺귯��
#pragma comment (lib, "Xaudio2.lib")
#pragma comment (lib, "mfreadwrite.lib")
#pragma comment (lib, "mfplat.lib")
#pragma comment (lib, "mfuuid")

//����� â������ �ܼ��� ����, ��������� �ܼ��� ����� �ʱ� ���� �����Դϴ�.
#ifndef _DEBUG
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#else
#    pragma comment(linker, "/SUBSYSTEM:CONSOLE /ENTRY:mainCRTStartup")
#endif

//SAFE_RELEASE, SAFE_DELETE�� ��Ÿ ��ũ�� �Լ��Դϴ�.
#define SAFE_RELEASE(p) { if(p){p->Release();} p=NULL; }
#define SAFE_DELETE(p) {if(p!=nullptr){delete(p);} p=nullptr; }
#define PI 3.141592653589793f
#define RADTOEULER -180.0f/PI

//Direct2D�� ������ ����ü�� �ѹ� �� typedef���־����ϴ�.
typedef D2D1_POINT_2F Point;