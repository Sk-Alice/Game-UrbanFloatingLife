#pragma once
#include "GameInfoView.h"
#include "BlackMarket.h"

/* 地铁站界面 */

class StationView : GameInfoView
{
private:
	// 显示地铁示意图
	void showStationNet();


public:
	StationView();
	virtual ~StationView();

	void show() override;
};

