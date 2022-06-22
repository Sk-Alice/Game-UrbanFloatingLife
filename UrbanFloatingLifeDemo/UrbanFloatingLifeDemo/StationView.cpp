#include "StationView.h"
#include "GameWorld.h"
#include "Viewer.h"
#include "MarketView.h"

StationView::StationView()
{

}

StationView::~StationView()
{

}

void StationView::show()
{
	GameInfoView::show();

	showStationNet();
}

void StationView::showStationNet()
{
	vector<string> names;
	auto stations = *GameWorld::getInstance()->getStations();
	for (auto station : stations)
	{
		names.push_back(station->getName());
	}

	// ���ѡ��ĵ���վ���
	int id = Viewer::chooseMenuItem("���е���ʾ��ͼ", names);
	unsigned int num = id - 1;
	// ��ʾ���н���
	auto marketView = MarketView::create(stations[num]->getMarket());
	marketView->show();
	delete marketView;
}

