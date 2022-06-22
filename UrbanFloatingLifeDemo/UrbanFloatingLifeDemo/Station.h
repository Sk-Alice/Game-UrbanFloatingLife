#pragma once
#include "BlackMarket.h"

using namespace std;

/* ����վ */

class Station
{
private:
	int prt_id;
	string prt_name;

	// ����
	BlackMarket* prt_market;

public:
	Station();
	virtual ~Station();

	// ��ȡ��ǰ����վ����
	BlackMarket* getMarket();

	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getName() { return prt_name; }
	void setName(string name) { prt_name = name; }

};

