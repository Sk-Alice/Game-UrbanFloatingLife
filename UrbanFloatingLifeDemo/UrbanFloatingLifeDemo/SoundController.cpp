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
		是windows播放音乐的API函数的方法，只能播放wav或wav格式的音频文件
		调用系统音频的播放器
		BOOL PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
		返回值：返回参数3是否起作用的结果
		参数1：要播放声音的字符串 -- 音频文件路径 -- 直接传入空字符串表示停止播放
		参数2：应用程序的实例句柄 -- 一般是NULL
		参数3：标志组合 -- 通过 | 连接
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

	stringstream cmd;	// 用来字符串的拼接
	cmd << "play res/";
	cmd << id;
	cmd << ".wav";

	//先获取转换成宽字符后的长度（一定要通过这种方式，先回去字符长度，因为有指定编码为CP_ACP，编码不同，长度也会不同）
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, NULL, 0);
	//声明一个宽字符类型变量，用于存放转换后的字符
	wchar_t* wcmd = new wchar_t[nLen];
	//利用微软ANSI转宽字符的函数（name:ANSI字符，wname:宽字符）
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, wcmd, nLen);

	/*
		mci -- Media control interface(媒体控制接口)
		mciSendString(LPCTSTR lpszCommand, LPTSTR lpszReturnString, UINT cchReturn, HANDLE hwndCallback)
		功能：播放MPEG AVI WAV MP3 ID 等
		调用多媒体的播放器 -- 调用的底层不同，因此可以与PlaySound结合同时播放两个音效
	*/
	mciSendString(wcmd, NULL, 0, NULL);
}

void SoundController::stopSound(int id)
{
	stringstream cmd;
	cmd << "stop res/";
	cmd << id;
	cmd << ".wav";

	//先获取转换成宽字符后的长度（一定要通过这种方式，先回去字符长度，因为有指定编码为CP_ACP，编码不同，长度也会不同）
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, NULL, 0);
	//声明一个宽字符类型变量，用于存放转换后的字符
	wchar_t* wcmd = new wchar_t[nLen];
	//利用微软ANSI转宽字符的函数（name:ANSI字符，wname:宽字符）
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cmd.str().c_str(), -1, wcmd, nLen);

	mciSendString(wcmd, NULL, 0, NULL);
}

void SoundController::stopAll()
{
	// 停止播放所有音效
	int soundIds[] = { 10001 };
	int len = sizeof(soundIds) / sizeof(int);

	for (int i = 0; i < len; i++)
	{
		stopSound(soundIds[i]);
	}

	// 停止播放背景音乐
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

