#pragma once
/* 声音控制器 */

class SoundController
{
private:
	static SoundController* instance;

	// 是否静音
	bool prt_isSilence;

public:
	SoundController();
	virtual ~SoundController();

	static SoundController* getInstance();

	// 播放音效
	void playSound(int id);
	// 停止播放音效
	void stopSound(int id);

	// 播放背景音乐
	void playBGM();
	// 停止播放音乐
	void stopBGM();

	// 停止所有的声音播放
	void stopAll();

	// 获取是否静音的状态
	bool getSilence();
	// 设置是否静音
	void setSilence(bool isSilence);

};

