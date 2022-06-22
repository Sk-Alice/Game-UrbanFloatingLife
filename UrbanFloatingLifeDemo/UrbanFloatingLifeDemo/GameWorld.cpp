#include "GameWorld.h"
#include "GameRole.h"

GameWorld::GameWorld()
{
	prt_currDay = 0;
	prt_maxDay = 40;
	// 初始化游戏角色
	prt_role = nullptr;
	// 初始化游戏场景
	string names[] = { "地铁站", "银行", "邮局", "医院", "机场", "租房中介", "网吧" };
	for (int i = 0; i < sizeof(names) / sizeof(*names); i++)
	{
		GamePlace* place = new GamePlace();
		place->setId(i + 1);
		place->setName(names[i]);

		prt_places.push_back(place);
	}

	// 初始化游戏物品
	string goodsNames[] = {
		"进口香烟                 ",
		"走私汽车                 ",
		"盗版VCD、游戏            ",
		"假白酒(剧毒！)           ",
		"《都市小宝贝》           ",
		"进口玩具                 ",
		"伪劣化妆品               ",
		"水货手机                 "
	};

	const int goodsSize = sizeof(goodsNames) / sizeof(*goodsNames);
	int goodsPrice[goodsSize][2] = {
		{100, 400},// 进口香烟的价格波动范围
		{15000, 30000},// 走私汽车
		{5, 55},// 盗版VCD、游戏
		{1000, 3500},// 假白酒(剧毒！)
		{5000, 9000},// 《都市小宝贝》
		{250, 850},// 进口玩具的
		{65, 245},// 伪劣化妆品
		{750, 1500}// 水货手机
	};

	for (int i = 0; i < goodsSize; i++)
	{
		GameGoods* goods = new GameGoods();
		goods->setId(i + 1);
		goods->setName(goodsNames[i]);
		goods->setMinPrice(goodsPrice[i][0]);
		goods->setMaxPrice(goodsPrice[i][1]);

		prt_goods.insert(pair<int, GameGoods*>(goods->getId(), goods));
	}

	//初始化地铁站列表
	string stationNames[] = {
		"西直门",
		"积水潭",
		"东直门",
		"苹果园",
		"公主坟",
		"复兴门",
		"建国门",
		"长椿街",
		"崇文门",
		"北京站"
	};

	for (int i = 0; i < sizeof(stationNames) / sizeof(*stationNames); i++)
	{
		Station* station = new Station();
		station->setId(i + 1);
		station->setName(stationNames[i]);

		prt_stations.push_back(station);
	}

	prt_currMessage = nullptr;
}

GameWorld::~GameWorld()
{
	if (prt_role)
	{
		delete prt_role;
		prt_role = nullptr;
	}
}

// 初始化单例对象
GameWorld* GameWorld::instance = nullptr;
GameWorld* GameWorld::getInstance()
{
	if (instance == nullptr)
	{
		instance = new GameWorld();
	}

	return instance;
}

int GameWorld::getCurrDay()
{
	return prt_currDay;
}

void GameWorld::setCurrDay(int day)
{
	this->prt_currDay = day;
}

int GameWorld::getMaxDay()
{
	return prt_maxDay;
}

GameRole* GameWorld::getGameRole()
{
	if (!prt_role)
	{
		prt_role = new GameRole();
	}

	return prt_role;
}


