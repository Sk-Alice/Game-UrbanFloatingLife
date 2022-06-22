#pragma once
#include "BlackMarket.h"
#include "GameInfoView.h"

/* ���н��� */

class MarketView : public GameInfoView
{
private:
	// ����ʵ��
	BlackMarket* prt_market;

	// ��Ʒ�ͻ����б��ˢ����ʾ
	void updateShowList(BlackMarket* market);

	// ���׹��ܲ˵�
	void showMenu();

protected:
	MarketView();

public:
	/* ����һ�����н���ʵ�� */
	static MarketView* create(BlackMarket* market);
	virtual ~MarketView();

	void show() override;
};

