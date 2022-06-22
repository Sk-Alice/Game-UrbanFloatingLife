#include <windows.h>
#include <mmsystem.h>
#include "SoundController.h"
#include <sstream>
#pragma comment(lib,"WINMM.lib")

using namespace std;

SoundController::SoundController()
{
	prt_isSilence = false;
}

SoundController::~SoundController()
{

}

SoundController* SoundController::instance = nullptr;
SoundController* SoundController::getInstance()
{
	if (!instance)
	{
		instance = new SoundController();
	}

	return instance;
}

void SoundController::playBGM()
{
	if (prt_isSilence) return;
	/*
		PlaySound()
		��windows�������ֵ�API�����ķ�����ֻ�ܲ���wav��wav��ʽ����Ƶ�ļ�
		����ϵͳ��Ƶ�Ĳ�����
		BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
		����ֵ�����ز���3�Ƿ������õĽ��
		����1��Ҫ�����������ַ��� -- ��Ƶ�ļ�·�� -- ֱ�Ӵ�����ַ�����ʾֹͣ����
		����2��Ӧ�ó����ʵ����� -- һ����NULL
		����3����־��� -- ͨ�� | ����
	*/
	PlaySound(TEXT("res./1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void SoundController::stopBGM()
{
	PlaySound(TEXT(""), NULL, SND_FILENAME);
}

void SoundController::playSound(int id)
{
	if (prt_isSilence) return;

	stringstream cmd;	// �����ַ�����ƴ��
	cmd << "play res/";
	cmd << id;
	cmd << ".wav";

	//�Ȼ�ȡת���ɿ��ַ���ĳ��ȣ�һ��Ҫͨ�����ַ�ʽ���Ȼ�ȥ�ַ����ȣ���Ϊ��ָ������ΪCP_ACP�����벻ͬ������Ҳ�᲻ͬ��
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, NULL, 0);
	//����һ�����ַ����ͱ��������ڴ��ת������ַ�
	wchar_t* wcmd = new wchar_t[nLen];
	//����΢��ANSIת���ַ��ĺ�����name:ANSI�ַ���wname:���ַ���
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, wcmd, nLen);

	/*
		mci -- Media control interface(ý����ƽӿ�)
		mciSendString(LPCTSTR lpszCommand, LPTSTR lpszReturnString, UINT cchReturn, HANDLE hwndCallback)
		���ܣ�����MPEG AVI WAV MP3 ID ��
		���ö�ý��Ĳ����� -- ���õĵײ㲻ͬ����˿�����PlaySound���ͬʱ����������Ч
	*/
	mciSendString(wcmd, NULL, 0, NULL);
}

void SoundController::stopSound(int id)
{
	stringstream cmd;
	cmd << "stop res/";
	cmd << id;
	cmd << ".wav";

	//�Ȼ�ȡת���ɿ��ַ���ĳ��ȣ�һ��Ҫͨ�����ַ�ʽ���Ȼ�ȥ�ַ����ȣ���Ϊ��ָ������ΪCP_ACP�����벻ͬ������Ҳ�᲻ͬ��
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, NULL, 0);
	//����һ�����ַ����ͱ��������ڴ��ת������ַ�
	wchar_t* wcmd = new wchar_t[nLen];
	//����΢��ANSIת���ַ��ĺ�����name:ANSI�ַ���wname:���ַ���
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, wcmd, nLen);

	mciSendString(wcmd, NULL, 0, NULL);
}

void SoundController::stopAll()
{
	// ֹͣ����������Ч
	int soundIds[] = { 10001 };
	int len = sizeof(soundIds) / sizeof(int);

	for (int i = 0; i < len; i++)
	{
		stopSound(soundIds[i]);
	}

	// ֹͣ���ű�������
	stopBGM();
}

bool SoundController::getSilence()
{
	return prt_isSilence;
}

void SoundController::setSilence(bool isSlience)
{
	this->prt_isSilence = isSlience;
}

