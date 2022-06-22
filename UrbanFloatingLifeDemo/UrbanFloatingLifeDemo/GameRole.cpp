#include <vector>
#include "GameRole.h"

using namespace std;

GameRole::GameRole()
{
	// 默认现金2000
	prt_cash = 2000;
	// 默认存款0
	prt_deposit = 0.00f;
	// 默认欠债5500
	prt_debt = 5500.00f;
	// 默认健康值100
	prt_hp = 100;
	// 默认名声100
	prt_fame = 100;
	// 默认当前储存
	prt_currStore = 0;
	// 默认最大储存
	prt_maxStore = 100;
}

GameRole::~GameRole()
{

}

int GameRole::sell(GameGoods* commodity, int amounts)
{
	// 货物是否存在 -- 通过编号查找货物
	GameGoods* storeGoods = nullptr;
	for (auto goods : prt_goods)
	{
		if (goods->getId() == commodity->getId())
		{
			storeGoods = goods;
			break;
		}
	}
	// 货物不存在
	if (!storeGoods) return 0;

	// 货物数量是否充足
	int number = storeGoods->getCount();
	// 数量不足
	if (amounts > number) return 1;


	// 玩家现金增加
	setCash(getCash() + commodity->getPrice() * amounts);

	// 玩家当前库存总数减少
	setCurrStore(getCurrStore() - amounts);

	// 玩家货物库存减少(全部卖出，从列表中移除货物)
	if (amounts == number)
	{
		auto itor = prt_goods.begin();
		while (itor != prt_goods.end())
		{
			auto store = *itor;
			if (store->getId() == commodity->getId())
			{
				prt_goods.erase(itor);
				break;
			}
			itor++;
		}
	}
	else
	{
		storeGoods->setCount(number - amounts);
	}

	return 2;
}
