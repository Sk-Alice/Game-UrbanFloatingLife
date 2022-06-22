#include <vector>
#include "GameRole.h"

using namespace std;

GameRole::GameRole()
{
	// Ĭ���ֽ�2000
	prt_cash = 2000;
	// Ĭ�ϴ��0
	prt_deposit = 0.00f;
	// Ĭ��Ƿծ5500
	prt_debt = 5500.00f;
	// Ĭ�Ͻ���ֵ100
	prt_hp = 100;
	// Ĭ������100
	prt_fame = 100;
	// Ĭ�ϵ�ǰ����
	prt_currStore = 0;
	// Ĭ����󴢴�
	prt_maxStore = 100;
}

GameRole::~GameRole()
{

}

int GameRole::sell(GameGoods* commodity, int amounts)
{
	// �����Ƿ���� -- ͨ����Ų��һ���
	GameGoods* storeGoods = nullptr;
	for (auto goods : prt_goods)
	{
		if (goods->getId() == commodity->getId())
		{
			storeGoods = goods;
			break;
		}
	}
	// ���ﲻ����
	if (!storeGoods) return 0;

	// ���������Ƿ����
	int number = storeGoods->getCount();
	// ��������
	if (amounts > number) return 1;


	// ����ֽ�����
	setCash(getCash() + commodity->getPrice() * amounts);

	// ��ҵ�ǰ�����������
	setCurrStore(getCurrStore() - amounts);

	// ��һ��������(ȫ�����������б����Ƴ�����)
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
