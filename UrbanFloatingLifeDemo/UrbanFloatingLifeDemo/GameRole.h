#pragma once
#include <vector>
#include "GameGoods.h"

using namespace std;

/* ��ҽ�ɫ�� */

class GameRole
{
private:
	int prt_cash;
	float prt_deposit;
	float prt_debt;
	int prt_hp;
	int prt_fame;

	// ��ҳ������еĻ���
	vector<GameGoods*> prt_goods;

	// ��ǰ�������
	int prt_currStore;
	// ���������
	int prt_maxStore;

public:
	GameRole();
	virtual ~GameRole();

	// ��ȡ��ҵĻ���
	vector<GameGoods*>* getGoods() { return &prt_goods; }

	// ��ҳ�����Ʒ
	int sell(GameGoods* commodity, int amount);

	int getCash() { return prt_cash; }
	void setCash(int cash) { prt_cash = cash; }
	float getDeposit() { return prt_deposit; }
	void setDeposit(float deposit) { prt_deposit = deposit; }
	float getDebt() { return prt_debt; }
	void setDebt(float debt) { prt_debt = debt; }
	int getHp() { return prt_hp; }
	void setHp(int hp) { prt_hp = hp; }
	int getFame() { return prt_fame; }
	void setFame(int fame) { prt_fame = fame; }
	int getCurrStore() { return prt_currStore; }
	void setCurrStore(int currStore) { prt_currStore = currStore; }
	int getMaxStore() { return prt_maxStore; }
	void setMaxStore(int maxStore) { prt_maxStore = maxStore; }

};

