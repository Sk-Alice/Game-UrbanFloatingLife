#include <algorithm>	// sort()
#include "GameCore.h"
#include "GameWorld.h"
#include "Viewer.h"
#include "RandomUtil.h"
#include "EventController.h"

using namespace std;

GameCore::GameCore()
{
	// 默认游戏暂停
	prt_gameState = false;
}

GameCore::~GameCore()
{

}

GameCore* GameCore::instance = nullptr;
GameCore* GameCore::getInstance()
{
	if (!instance)
	{
		instance = new GameCore();
	}

	return instance;
}

void GameCore::gameNewStart()
{
	EventController::getInstance()->loadingDate();
	prt_gameState = true;

	// 游戏主循环
	while (prt_gameState)
	{
		// 逻辑刷新
		LogicUpdate();

		// 显示刷新
		showUpdate();
	}
}

void GameCore::game_end()
{
	prt_gameState = false;

}

void GameCore::LogicUpdate()
{
	auto world = GameWorld::getInstance();
	// 如果没有到40天，天数 +1
	if (world->getCurrDay() <= world->getMaxDay())
	{
		world->setCurrDay(world->getCurrDay() + 1);

		// 重置记录的消息内容
		GameWorld::getInstance()->setCurrMessage(nullptr);

		// 新的一天 -- 触发事件
		if (RandomUtil::getProbabilityResult(50))
		{
			// 成功触发事件，随机产生一个消息
			int id = RandomUtil::getRandomInteger(1, world->getMessages()->size());
			EventController::getInstance()->playMessage(id);
		}

		// 遍历地铁站列表
		for (auto station : *world->getStations())
		{
			// 刷新黑市商品列表
			updateMarketList(station->getMarket());
		}
	}
	else
	{
		game_end();
	}
}

void GameCore::showUpdate()
{
	auto world = GameWorld::getInstance();
	if (world->getCurrDay() > world->getMaxDay()) return;

	Viewer::getInstance()->gameStartShow();
}

void GameCore::updateMarketList(BlackMarket* market)
{
	// 随机物品类型的数量(5-7)种
	int amounts = RandomUtil::getRandomInteger(5, 7);

	// 记录所有物品编号的集合，保证每产生一个物品，就移除它的编号，确保不会有重复物品产生
	auto world = GameWorld::getInstance();
	auto allGoods = world->getAllGoods();
	vector<int> allIds;
	for (int i = 0; i < allGoods->size(); i++)
	{
		allIds.push_back(i + 1);
	}

	// 随机生成一组物品
	vector<int> randomIds;
	int i = 0;
	while (i < amounts)
	{
		int minIndex = 0;
		int maxIndex = allIds.size() - 1;

		// 随机产生allIds集合中的一个物品编号的下标
		int randIndex = RandomUtil::getRandomInteger(minIndex, maxIndex);

		// 记录随机产生的物品编号
		randomIds.push_back(allIds[randIndex]);

		// 移除allIds中指定的编号
		allIds.erase(allIds.begin() + randIndex);
		i++;
	}

	// 物品随机产生价格
	auto goodsList = market->getList();
	goodsList->clear();
	sort(randomIds.begin(), randomIds.end());
	for (int goodsId : randomIds)
	{
		// 获取物品实例
		GameGoods* goods = allGoods->at(goodsId);

		// 在价格波动范围内随机产生价格
		int randomPrice = RandomUtil::getRandomInteger(goods->getMinPrice(), goods->getMaxPrice());

		// 如果有消息，会对指定商品的价格产生影响
		Message* message = world->getCurrMessage();
		if (message && message->getGoodsId() == goodsId)
		{
			if (message->getPriceInc() > 0)
			{
				randomPrice = randomPrice * message->getPriceInc();
			}
			else if (message->getPriceDec() > 0)
			{
				randomPrice = randomPrice / message->getPriceDec();
			}
		}

		//创建一个商品实例，与游戏世界中的物品实例不同
		GameGoods* commodity = new GameGoods();
		commodity->setId(goods->getId());
		commodity->setName(goods->getName());
		commodity->setCount(100);
		commodity->setPrice(randomPrice);

		goodsList->push_back(commodity);
	}
}