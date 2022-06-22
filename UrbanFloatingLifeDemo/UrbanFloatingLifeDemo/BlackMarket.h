#pragma once
#include <vector>
#include "GameGoods.h"

using namespace std;

/* 黑市 */

class BlackMarket
{
private:
	int prt_id;
	string prt_name;

	// 商品列表
	vector<GameGoods*> prt_list;

public:
	BlackMarket();
	virtual ~BlackMarket();

	// 获取商品列表
	vector<GameGoods*>* getList() { return &prt_list; }

	// 黑市商品出售
	int sell(int id, int amounts);

	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getName() { return prt_name; }
	void setName(string name) { prt_name = name; }
};

