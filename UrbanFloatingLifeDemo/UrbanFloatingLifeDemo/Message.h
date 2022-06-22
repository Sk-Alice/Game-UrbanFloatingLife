#pragma once
#include <string>

using namespace std;

/* Ӱ����Ʒ�۸����������Ϣ����ģ�� */

class Message
{
private:
	int prt_id;		   // ��Ϣ���
	string prt_content;// ��Ϣ����
	int prt_goodsId;   // Ӱ�����Ʒ���
	int prt_priceInc;  // ��Ʒ�۸����ӱ���
	int prt_priceDec;  // ��Ʒ�۸���ٱ���
	int prt_goodsCount;// ��Ϸ��ɫ���ӵĻ�������

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

