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

	// 玩家选择的地铁站编号
	int id = Viewer::chooseMenuItem("城市地铁示意图", names);
	unsigned int num = id - 1;
	// 显示黑市界面
	auto marketView = MarketView::create(stations[num]->getMarket());
	marketView->show();
	delete marketView;
}

