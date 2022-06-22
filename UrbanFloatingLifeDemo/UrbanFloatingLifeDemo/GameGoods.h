#pragma once
#include <string>

using namespace std;

/* 商品 */

class GameGoods
{
private:
	// 物品编号
	int prt_id;
	// 物品名称
	string prt_name;
	// 物品售价
	int prt_price;
	// 商品购买价格
	int prt_buyPrice;
	// 商品最小价格
	int prt_minPrice;
	// 商品最大价格
	int prt_maxPrice;
	// 物品数量
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

