#include "GameMainView.h"
#include "Viewer.h"
#include "GameWorld.h"
#include "StationView.h"

GameMainView::GameMainView()
{

}

GameMainView::~GameMainView()
{

}

void GameMainView::show()
{
	// 调用父类的show方法
	GameInfoView::show();

	// 显示游戏功能选择菜单
	showFuncChoice();
}

void GameMainView::showFuncChoice()
{
	auto world = GameWorld::getInstance();
	// 获取功能项名称集合
	vector<string> items;
	for (auto place : *world->getGamePlaces())
	{
		items.push_back(place->getName());
	}
	items.push_back("开始新的一天");
	items.push_back("结束游戏");

	switch (Viewer::chooseMenuItem("城市地面示意图:", items))
	{
	case 1:	// 地铁站
	{
		// 创建地铁站示例图界面
		StationView* stationView = new StationView();
		stationView->show();
		delete stationView;
	}
	return;
	case 2: // 银行
		break;
	case 3:	// 邮局
		break;
	case 4:	// 医院
		break;
	case 5:	// 机场
		break;
	case 6:	// 租房中介
		break;
	case 7:	// 网吧
		break;
	case 8:	// 开始新的一天
	{
		auto role = world->getGameRole();
		// 玩家的存款利息
		float result = role->getDeposit() * 1.05f;
		role->setDeposit(result);
		// 玩家的欠债利息
		result = role->getDebt() * 1.1f;
		role->setDebt(result);
	}
	return;
	break;
	case 9:	// 退出游戏
		break;
	default:
		break;
	}
}
