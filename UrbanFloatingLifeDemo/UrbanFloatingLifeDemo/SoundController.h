#pragma once
/* ���������� */

class SoundController
{
private:
	static SoundController* instance;

	// �Ƿ���
	bool prt_isSilence;

public:
	SoundController();
	virtual ~SoundController();

	static SoundController* getInstance();

	// ������Ч
	void playSound(int id);
	// ֹͣ������Ч
	void stopSound(int id);

	// ���ű�������
	void playBGM();
	// ֹͣ��������
	void stopBGM();

	// ֹͣ���е���������
	void stopAll();

	// ��ȡ�Ƿ�����״̬
	bool getSilence();
	// �����Ƿ���
	void setSilence(bool isSilence);

};

