#pragma once
/* ��Ϸ������ */

class GameController
{
private:
	static GameController* instance;

public:
	GameController();
	virtual ~GameController();

	// ��ϵͳ�ṩʵ�� - ��ȡ��������
	static GameController* getInstance();
	// ��Ϸ��ʼ
	void game_start();
	// ��Ϸ����
	void game_end();
};
