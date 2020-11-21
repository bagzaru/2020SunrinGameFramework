#pragma once
#include "stdafx.h"

//Xaudio2�� ����ϴ� ����� ���� Ŭ�����Դϴ�.
//�⺻������ ������� ����ϱ� ���� ����, ȯ���� ����մϴ�.
//���� ���� �ε�, ����� SoundEvent Ŭ������ ���� �̷����ϴ�.
class Audio
{
public:
	Audio();
	~Audio();

	IXAudio2* xaudio2;						//XAudio2 ���� �ν��Ͻ�
	IXAudio2MasteringVoice* masterVoice;	//������ ���̽�
	IMFAttributes* sourceReaderConfiguration;

	//�ʱ�ȭ, ����
	bool Initialize();
	void Uninitialize();

	//����� ���� �ε�
	//mp3, wav���� ������ Wav ���� �������� ��ȯ�Ͽ� ���˴ϴ�.
	bool LoadFile(const wchar_t* path, std::vector<BYTE>& audioData, WAVEFORMATEX** waveFormatEx, unsigned int& waveLength);

	//�̱��� ����
	//���� �� ����� ��ü�� �޾ƿɴϴ�.
	static Audio* GetInstance();
};