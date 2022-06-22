#include "EventController.h"
#include "GameWorld.h"

#include <string>

using namespace std;

EventController::EventController()
{

}

EventController::~EventController()
{

}

EventController* EventController::instance = nullptr;
EventController* EventController::getInstance()
{
	if (!instance)
	{
		instance = new EventController();
	}

	return instance;
}

// 随机消息数据 结构体
typedef struct tagMessageType
{
	string content;// 消息内容
	int goodsId;   // 影响的物品编号
	int priceInc;  // 商品价格增加倍数
	int priceDec;  // 商品价格减少倍数
	int goodsCount;// 游戏角色增加的货物数量
}Msg;

#define GAME_MESSAGE_COUNT 3
Msg messageConfig[GAME_MESSAGE_COUNT] = {
	{"专家提议提高大学生“动手素质”,进口玩具颇受欢迎", 6, 2, 0, 0},
	{"厦门的老同学资助我两辆走私汽车！发了！！！", 2, 0, 0, 2},
	{"市场上充斥着来自福建的走私香烟！", 1, 0, 8, 0}
};

void EventController::loadingDate()
{
	auto goodsMessage = GameWorld::getInstance()->getMessages();
	for (int i = 0; i < GAME_MESSAGE_COUNT; i++)
	{
		Msg msg = messageConfig[i];
		Message* message = new Message();
		message->setId(i + 1);
		message->setGoodsId(msg.goodsId);
		message->setContent(msg.content);
		message->setPriceInc(msg.priceInc);
		message->setPriceDec(msg.priceDec);
		message->setGoodsCount(msg.goodsCount);

		goodsMessage->insert(pair<int, Message*>(message->getId(), message));

	}
}

void EventController::playMessage(int id)
{
	auto world = GameWorld::getInstance();
	auto currMessage = world->getMessages()->at(id);
	if (currMessage)
	{
		world->setCurrMessage(currMessage);

		// 修改玩家货物数量
		if (currMessage->getGoodsCount() > 0)
		{
			int goodsId = currMessage->getGoodsId();
			auto role = world->getGameRole();
			auto storeGoods = role->getGoods();

			// 通过编号查找货物
			GameGoods* gameGoods = nullptr;
			for (auto store : *storeGoods)
			{
				if (store->getId() == goodsId)
				{
					gameGoods = store;
					break;
				}
			}

			// 货物存在，数量增加
			if (gameGoods)
			{
				// 超出库存上限不处理边界值
				int amounts = gameGoods->getCount();
				gameGoods->setCount(amounts + currMessage->getGoodsCount());
				gameGoods->setBuyPrice(amounts * gameGoods->getBuyPrice() / gameGoods->getCount());
			}
			// 货物不存在，增加货物
			else
			{
				gameGoods = new GameGoods();
				gameGoods->setId(goodsId);
				// 查找物品的名字
				auto goodsConfig = world->getAllGoods()->at(goodsId);
				if (goodsConfig)
				{
					gameGoods->setName(goodsConfig->getName());
				}

				gameGoods->setBuyPrice(0);
				gameGoods->setCount(currMessage->getGoodsCount());

				storeGoods->push_back(gameGoods);
			}
		}
	}
}