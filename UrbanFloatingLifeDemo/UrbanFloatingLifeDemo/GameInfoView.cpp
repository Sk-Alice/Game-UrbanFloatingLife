#include <Windows.h>
#include "GameInfoView.h"
#include "GameWorld.h"

using namespace std;

GameInfoView::GameInfoView()
{
	prt_currDay = 0;
	prt_maxDay = 40;
	prt_role = nullptr;
}

GameInfoView::~GameInfoView()
{

}

void GameInfoView::show()
{
	system("cls");

	auto world = GameWorld::getInstance();
	prt_currDay = world->getCurrDay();
	prt_maxDay = world->getMaxDay();
	prt_role = world->getGameRole();

	// ��ʾʱ��
	showDay();
	// ��ʾ����¼�
	showEvent();
	// ��ʾ��ɫ��Ϣ
	showRoleInfo();
}

void GameInfoView::showDay()
{
	if (prt_currDay == 1)
	{
		cout << "�������˸���֮�ã�" << endl;
	}
	cout << "��" << prt_currDay << "��/" << prt_maxDay << "��" << endl;
}

void GameInfoView::showEvent()
{
	Message* message = GameWorld::getInstance()->getCurrMessage();
	if (!message) return;
	int width = 62;
	// ��һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;

	// Ӱ����Ʒ�۸����Ϣ
	cout << "��������" << endl;

	// ����ָ���
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;

	// ��ӡ��Ϣ����
	cout << message->getContent() << endl;

	// ���һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;


}

void GameInfoView::showRoleInfo()
{
	// ���������Ϣ�߿�
	int width = 62;
	// ��һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;

	// ��ʾ����
	vector<string> infos;
	infos.push_back("�����Ϣ��");
	infos.push_back(showFormatForRoleProp(1, "�ֽ�", prt_role->getCash(), "Ԫ"));
	infos.push_back(showFormatForRoleProp(2, "���", prt_role->getDeposit(), "Ԫ"));
	infos.push_back(showFormatForRoleProp(3, "Ƿծ", prt_role->getDebt(), "Ԫ"));
	infos.push_back(showFormatForRoleProp(4, "����", prt_role->getHp()));
	infos.push_back(showFormatForRoleProp(5, "����", prt_role->getFame()));

	for (string content : infos)
	{
		cout << "*";
		// ��ӡleft���ո�
		int left = 2;
		for (int i = 0; i < left; i++)
		{
			cout << " ";
		}

		// ��ӡ����
		cout << content;

		// ��ӡ�Ҳ�ո� = �ܿ�� - ���ݳ��� - ǰ��*ռ�������ַ� - ǰ��Ŀո���left
		size_t right = width - content.length();
		for (int i = 0; i < right - 2 - left; i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}

	// ���һ�зָ���
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;
}

string GameInfoView::showFormatForRoleProp(int id, string name, int money, string unit)
{
	stringstream sstream;
	sstream << id << ".";
	sstream << name << "�� ";
	sstream << setw(10) << money << "  ";
	sstream << unit;

	return sstream.str();
}

