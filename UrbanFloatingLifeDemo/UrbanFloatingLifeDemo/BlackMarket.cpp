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
	// 通过编号查找商品
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

	// 判断商品数量是否充足
	int goodsAmounts = commdity->getCount();
	if (goodsAmounts < amounts)
	{
		// 数量不足
		return 1;
	}

	// 扣除玩家现金
	GameRole* role = GameWorld::getInstance()->getGameRole();
	int cash = role->getCash();
	int sellTotalPrice = amounts * commdity->getPrice();
	// 现金不足
	if (cash < sellTotalPrice)
	{
		return 3;
	}

	// 判断库存是否达到上限
	int total = role->getCurrStore() + amounts;
	if (total > role->getMaxStore())
	{
		return 4;
	}

	// 现金充足，扣除玩家现金
	role->setCash(cash - sellTotalPrice);

	// 记录当前货物总数
	role->setCurrStore(total);

	// 数量足够
	commdity->setCount(goodsAmounts - amounts);

	// 将购买货物放入玩家仓库(出租屋)
	auto allStoreGoods = role->getGoods();
	GameGoods* storeGoods = nullptr;

	// 在仓库中寻找是否有该货物
	for (auto store : *allStoreGoods)
	{
		if (store->getId() == id)
		{
			storeGoods = store;
			break;
		}
	}
	// 在仓库中没有找到该物品，创建一个货物实例放入
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
		// 计算前一次的购买总价
		int LastTotal = storeGoods->getBuyPrice() * storeGoods->getCount();

		// 在仓库中找到该物品，直接 + 购买的数量
		storeGoods->setCount(storeGoods->getCount() + amounts);

		// 重新计算总购买价格 （前一次购买总价+本次购买总价）/ 总数量
		storeGoods->setBuyPrice((LastTotal + sellTotalPrice) / storeGoods->getCount());

	}

	return 2;
}
