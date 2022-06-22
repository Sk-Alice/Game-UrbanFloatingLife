#pragma once
#include <string>

using namespace std;

/* 影响物品价格和数量的消息数据模型 */

class Message
{
private:
	int prt_id;		   // 消息编号
	string prt_content;// 消息内容
	int prt_goodsId;   // 影响的物品编号
	int prt_priceInc;  // 商品价格增加倍数
	int prt_priceDec;  // 商品价格减少倍数
	int prt_goodsCount;// 游戏角色增加的货物数量

public:
	Message();
	virtual ~Message();



	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getContent() { return prt_content; }
	void setContent(string content) { prt_content = content; }
	int getGoodsId() { return prt_goodsId; }
	void setGoodsId(int id) { prt_goodsId = id; }
	int getPriceInc() { return prt_priceInc; }
	void setPriceInc(int priceInc) { prt_priceInc = priceInc; }
	int getPriceDec() { return prt_priceDec; }
	void setPriceDec(int priceDec) { prt_priceDec = priceDec; }
	int getGoodsCount() { return prt_goodsCount; }
	void setGoodsCount(int goodsCount) { prt_goodsCount = goodsCount; }

};

