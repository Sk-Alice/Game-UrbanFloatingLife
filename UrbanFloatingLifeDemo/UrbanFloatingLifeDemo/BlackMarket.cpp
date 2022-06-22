#include "BlackMarket.h"
#include "GameWorld.h"

BlackMarket::BlackMarket()
{
	prt_id = 0;
	prt_name = "";
}

BlackMarket::~BlackMarket()
{

}

int BlackMarket::sell(int id, int amounts)
{
	// ͨ����Ų�����Ʒ
	GameGoods* commdity = nullptr;
	for (auto goods : prt_list)
	{
		if (goods->getId() == id)
		{
			commdity = goods;
			break;
		}
	}

	if (!commdity) return 0;

	// �ж���Ʒ�����Ƿ����
	int goodsAmounts = commdity->getCount();
	if (goodsAmounts < amounts)
	{
		// ��������
		return 1;
	}

	// �۳�����ֽ�
	GameRole* role = GameWorld::getInstance()->getGameRole();
	int cash = role->getCash();
	int sellTotalPrice = amounts * commdity->getPrice();
	// �ֽ���
	if (cash < sellTotalPrice)
	{
		return 3;
	}

	// �жϿ���Ƿ�ﵽ����
	int total = role->getCurrStore() + amounts;
	if (total > role->getMaxStore())
	{
		return 4;
	}

	// �ֽ���㣬�۳�����ֽ�
	role->setCash(cash - sellTotalPrice);

	// ��¼��ǰ��������
	role->setCurrStore(total);

	// �����㹻
	commdity->setCount(goodsAmounts - amounts);

	// ��������������Ҳֿ�(������)
	auto allStoreGoods = role->getGoods();
	GameGoods* storeGoods = nullptr;

	// �ڲֿ���Ѱ���Ƿ��иû���
	for (auto store : *allStoreGoods)
	{
		if (store->getId() == id)
		{
			storeGoods = store;
			break;
		}
	}
	// �ڲֿ���û���ҵ�����Ʒ������һ������ʵ������
	if (!storeGoods)
	{
		storeGoods = new GameGoods();
		storeGoods->setId(commdity->getId());
		storeGoods->setName(commdity->getName());
		storeGoods->setBuyPrice(commdity->getPrice());
		storeGoods->setCount(amounts);
		allStoreGoods->push_back(storeGoods);
	}
	else
	{
		// ����ǰһ�εĹ����ܼ�
		int LastTotal = storeGoods->getBuyPrice() * storeGoods->getCount();

		// �ڲֿ����ҵ�����Ʒ��ֱ�� + ���������
		storeGoods->setCount(storeGoods->getCount() + amounts);

		// ���¼����ܹ���۸� ��ǰһ�ι����ܼ�+���ι����ܼۣ�/ ������
		storeGoods->setBuyPrice((LastTotal + sellTotalPrice) / storeGoods->getCount());

	}

	return 2;
}
