#pragma once
#include "BlackMarket.h"

using namespace std;

/* 地铁站 */

class Station
{
private:
	int prt_id;
	string prt_name;

	// 黑市
	BlackMarket* prt_market;

public:
	Station();
	virtual ~Station();

	// 获取当前地铁站黑市
	BlackMarket* getMarket();

	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getName() { return prt_name; }
	void setName(string name) { prt_name = name; }

};

