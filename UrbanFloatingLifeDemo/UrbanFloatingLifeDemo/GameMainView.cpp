#include "GameMainView.h"
#include "Viewer.h"
#include "GameWorld.h"
#include "StationView.h"

GameMainView::GameMainView()
{

}

GameMainView::~GameMainView()
{

}

void GameMainView::show()
{
	// ���ø����show����
	GameInfoView::show();

	// ��ʾ��Ϸ����ѡ��˵�
	showFuncChoice();
}

void GameMainView::showFuncChoice()
{
	auto world = GameWorld::getInstance();
	// ��ȡ���������Ƽ���
	vector<string> items;
	for (auto place : *world->getGamePlaces())
	{
		items.push_back(place->getName());
	}
	items.push_back("��ʼ�µ�һ��");
	items.push_back("������Ϸ");

	switch (Viewer::chooseMenuItem("���е���ʾ��ͼ:", items))
	{
	case 1:	// ����վ
	{
		// ��������վʾ��ͼ����
		StationView* stationView = new StationView();
		stationView->show();
		delete stationView;
	}
	return;
	case 2: // ����
		break;
	case 3:	// �ʾ�
		break;
	case 4:	// ҽԺ
		break;
	case 5:	// ����
		break;
	case 6:	// �ⷿ�н�
		break;
	case 7:	// ����
		break;
	case 8:	// ��ʼ�µ�һ��
	{
		auto role = world->getGameRole();
		// ��ҵĴ����Ϣ
		float result = role->getDeposit() * 1.05f;
		role->setDeposit(result);
		// ��ҵ�Ƿծ��Ϣ
		result = role->getDebt() * 1.1f;
		role->setDebt(result);
	}
	return;
	break;
	case 9:	// �˳���Ϸ
		break;
	default:
		break;
	}
}
