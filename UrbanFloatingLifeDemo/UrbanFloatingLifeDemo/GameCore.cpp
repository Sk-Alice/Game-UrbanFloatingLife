#include <algorithm>	// sort()
#include "GameCore.h"
#include "GameWorld.h"
#include "Viewer.h"
#include "RandomUtil.h"
#include "EventController.h"

using namespace std;

GameCore::GameCore()
{
	// Ĭ����Ϸ��ͣ
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

	// ��Ϸ��ѭ��
	while (prt_gameState)
	{
		// �߼�ˢ��
		LogicUpdate();

		// ��ʾˢ��
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
	// ���û�е�40�죬���� +1
	if (world->getCurrDay() <= world->getMaxDay())
	{
		world->setCurrDay(world->getCurrDay() + 1);

		// ���ü�¼����Ϣ����
		GameWorld::getInstance()->setCurrMessage(nullptr);

		// �µ�һ�� -- �����¼�
		if (RandomUtil::getProbabilityResult(50))
		{
			// �ɹ������¼����������һ����Ϣ
			int id = RandomUtil::getRandomInteger(1, world->getMessages()->size());
			EventController::getInstance()->playMessage(id);
		}

		// ��������վ�б�
		for (auto station : *world->getStations())
		{
			// ˢ�º�����Ʒ�б�
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
	// �����Ʒ���͵�����(5-7)��
	int amounts = RandomUtil::getRandomInteger(5, 7);

	// ��¼������Ʒ��ŵļ��ϣ���֤ÿ����һ����Ʒ�����Ƴ����ı�ţ�ȷ���������ظ���Ʒ����
	auto world = GameWorld::getInstance();
	auto allGoods = world->getAllGoods();
	vector<int> allIds;
	for (int i = 0; i < allGoods->size(); i++)
	{
		allIds.push_back(i + 1);
	}

	// �������һ����Ʒ
	vector<int> randomIds;
	int i = 0;
	while (i < amounts)
	{
		int minIndex = 0;
		int maxIndex = allIds.size() - 1;

		// �������allIds�����е�һ����Ʒ��ŵ��±�
		int randIndex = RandomUtil::getRandomInteger(minIndex, maxIndex);

		// ��¼�����������Ʒ���
		randomIds.push_back(allIds[randIndex]);

		// �Ƴ�allIds��ָ���ı��
		allIds.erase(allIds.begin() + randIndex);
		i++;
	}

	// ��Ʒ��������۸�
	auto goodsList = market->getList();
	goodsList->clear();
	sort(randomIds.begin(), randomIds.end());
	for (int goodsId : randomIds)
	{
		// ��ȡ��Ʒʵ��
		GameGoods* goods = allGoods->at(goodsId);

		// �ڼ۸񲨶���Χ����������۸�
		int randomPrice = RandomUtil::getRandomInteger(goods->getMinPrice(), goods->getMaxPrice());

		// �������Ϣ�����ָ����Ʒ�ļ۸����Ӱ��
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

		//����һ����Ʒʵ��������Ϸ�����е���Ʒʵ����ͬ
		GameGoods* commodity = new GameGoods();
		commodity->setId(goods->getId());
		commodity->setName(goods->getName());
		commodity->setCount(100);
		commodity->setPrice(randomPrice);

		goodsList->push_back(commodity);
	}
}