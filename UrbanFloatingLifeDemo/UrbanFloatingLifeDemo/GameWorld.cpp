#include "GameWorld.h"
#include "GameRole.h"

GameWorld::GameWorld()
{
	prt_currDay = 0;
	prt_maxDay = 40;
	// ��ʼ����Ϸ��ɫ
	prt_role = nullptr;
	// ��ʼ����Ϸ����
	string names[] = { "����վ", "����", "�ʾ�", "ҽԺ", "����", "�ⷿ�н�", "����" };
	for (int i = 0; i < sizeof(names) / sizeof(*names); i++)
	{
		GamePlace* place = new GamePlace();
		place->setId(i + 1);
		place->setName(names[i]);

		prt_places.push_back(place);
	}

	// ��ʼ����Ϸ��Ʒ
	string goodsNames[] = {
		"��������                 ",
		"��˽����                 ",
		"����VCD����Ϸ            ",
		"�ٰ׾�(�綾��)           ",
		"������С������           ",
		"�������                 ",
		"α�ӻ�ױƷ               ",
		"ˮ���ֻ�                 "
	};

	const int goodsSize = sizeof(goodsNames) / sizeof(*goodsNames);
	int goodsPrice[goodsSize][2] = {
		{100, 400},// �������̵ļ۸񲨶���Χ
		{15000, 30000},// ��˽����
		{5, 55},// ����VCD����Ϸ
		{1000, 3500},// �ٰ׾�(�綾��)
		{5000, 9000},// ������С������
		{250, 850},// ������ߵ�
		{65, 245},// α�ӻ�ױƷ
		{750, 1500}// ˮ���ֻ�
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

	//��ʼ������վ�б�
	string stationNames[] = {
		"��ֱ��",
		"��ˮ̶",
		"��ֱ��",
		"ƻ��԰",
		"������",
		"������",
		"������",
		"������",
		"������",
		"����վ"
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

// ��ʼ����������
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


