#pragma once
#include <string>

using namespace std;

/* ��Ʒ */

class GameGoods
{
private:
	// ��Ʒ���
	int prt_id;
	// ��Ʒ����
	string prt_name;
	// ��Ʒ�ۼ�
	int prt_price;
	// ��Ʒ����۸�
	int prt_buyPrice;
	// ��Ʒ��С�۸�
	int prt_minPrice;
	// ��Ʒ���۸�
	int prt_maxPrice;
	// ��Ʒ����
	int prt_count;


public:
	GameGoods();
	virtual ~GameGoods();

	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getName() { return prt_name; }
	void setName(string name) { prt_name = name; }
	int getPrice() { return prt_price; }
	void setPrice(int price) { prt_price = price; }
	int getBuyPrice() { return prt_buyPrice; }
	void setBuyPrice(int buyPrice) { prt_buyPrice = buyPrice; }
	int getMinPrice() { return prt_minPrice; }
	void setMinPrice(int minPrice) { prt_minPrice = minPrice; }
	int getMaxPrice() { return prt_maxPrice; }
	void setMaxPrice(int maxPrice) { prt_maxPrice = maxPrice; }
	int getCount() { return prt_count; }
	void setCount(int count) { prt_count = count; }

};

