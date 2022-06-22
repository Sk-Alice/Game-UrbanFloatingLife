#pragma once
#include "BlackMarket.h"
/* ��Ϸ���� -- ����Ϸ�Ľ��̿��� */

class GameCore
{
private:
	static GameCore* instance;

	// ��Ϸ��״̬
	bool prt_gameState;

	// �߼�ˢ��
	void LogicUpdate();

	// ��ʾˢ��
	void showUpdate();

	// ����ָ�����е���Ʒ�б�
	void updateMarketList(BlackMarket* market);
public:
	GameCore();
	virtual ~GameCore();

	static GameCore* getInstance();
	void gameNewStart();
	void game_end();
};

