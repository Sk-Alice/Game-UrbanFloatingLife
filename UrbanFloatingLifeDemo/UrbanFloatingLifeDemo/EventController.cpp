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

// �����Ϣ���� �ṹ��
typedef struct tagMessageType
{
	string content;// ��Ϣ����
	int goodsId;   // Ӱ�����Ʒ���
	int priceInc;  // ��Ʒ�۸����ӱ���
	int priceDec;  // ��Ʒ�۸���ٱ���
	int goodsCount;// ��Ϸ��ɫ���ӵĻ�������
}Msg;

#define GAME_MESSAGE_COUNT 3
Msg messageConfig[GAME_MESSAGE_COUNT] = {
	{"ר��������ߴ�ѧ�����������ʡ�,����������ܻ�ӭ", 6, 2, 0, 0},
	{"���ŵ���ͬѧ������������˽���������ˣ�����", 2, 0, 0, 2},
	{"�г��ϳ�������Ը�������˽���̣�", 1, 0, 8, 0}
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

		// �޸���һ�������
		if (currMessage->getGoodsCount() > 0)
		{
			int goodsId = currMessage->getGoodsId();
			auto role = world->getGameRole();
			auto storeGoods = role->getGoods();

			// ͨ����Ų��һ���
			GameGoods* gameGoods = nullptr;
			for (auto store : *storeGoods)
			{
				if (store->getId() == goodsId)
				{
					gameGoods = store;
					break;
				}
			}

			// ������ڣ���������
			if (gameGoods)
			{
				// ����������޲�����߽�ֵ
				int amounts = gameGoods->getCount();
				gameGoods->setCount(amounts + currMessage->getGoodsCount());
				gameGoods->setBuyPrice(amounts * gameGoods->getBuyPrice() / gameGoods->getCount());
			}
			// ���ﲻ���ڣ����ӻ���
			else
			{
				gameGoods = new GameGoods();
				gameGoods->setId(goodsId);
				// ������Ʒ������
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