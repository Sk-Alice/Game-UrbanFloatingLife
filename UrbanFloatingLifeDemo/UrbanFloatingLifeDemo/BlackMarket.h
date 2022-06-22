#pragma once
#include <vector>
#include "GameGoods.h"

using namespace std;

/* ���� */

class BlackMarket
{
private:
	int prt_id;
	string prt_name;

	// ��Ʒ�б�
	vector<GameGoods*> prt_list;

public:
	BlackMarket();
	virtual ~BlackMarket();

	// ��ȡ��Ʒ�б�
	vector<GameGoods*>* getList() { return &prt_list; }

	// ������Ʒ����
	int sell(int id, int amounts);

	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getName() { return prt_name; }
	void setName(string name) { prt_name = name; }
};

