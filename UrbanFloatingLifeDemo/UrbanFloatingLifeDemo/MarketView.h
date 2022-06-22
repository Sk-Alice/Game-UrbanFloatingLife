#pragma once
#include "BlackMarket.h"
#include "GameInfoView.h"

/* 黑市界面 */

class MarketView : public GameInfoView
{
private:
	// 黑市实例
	BlackMarket* prt_market;

	// 商品和货物列表的刷新显示
	void updateShowList(BlackMarket* market);

	// 交易功能菜单
	void showMenu();

protected:
	MarketView();

public:
	/* 构建一个黑市界面实例 */
	static MarketView* create(BlackMarket* market);
	virtual ~MarketView();

	void show() override;
};

