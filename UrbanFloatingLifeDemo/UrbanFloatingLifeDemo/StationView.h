#pragma once
#include "GameInfoView.h"
#include "BlackMarket.h"

/* ����վ���� */

class StationView : GameInfoView
{
private:
	// ��ʾ����ʾ��ͼ
	void showStationNet();


public:
	StationView();
	virtual ~StationView();

	void show() override;
};

