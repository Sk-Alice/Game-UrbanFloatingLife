#include <iostream>
#include <Windows.h>	// Sleep() sysstem()
#include "Viewer.h"
#include "SoundController.h"
#include "GameCore.h"
#include "GameWorld.h"

using namespace std;

Viewer::Viewer()
{
	prt_mainView = nullptr;
}

Viewer::~Viewer()
{

}

// ��ʼ����������
Viewer* Viewer::instance = nullptr;
Viewer* Viewer::getInstance()
{
	if (!instance)
	{
		instance = new Viewer();
	}

	return instance;
}

void Viewer::showStory()
{
	// ��ȡ��������
	string story[] = {
		"****************************************************************",
		"*                    �����и����ǡ��Ĺ���                      *",
		"****************************************************************",
		"    ������һλ����ص�����ı�������ꡣ��ʼ����ֻ��2000ԪǮ������",
		"��Ƿ�峤(һ����åͷ��)5500��ծ����Щծ��ÿ�����Ϣ�ߴ�10%��  ",
		"�������ʱ���壬�峤������������������������������������������",
		"ͷ�����������������������е���������Ʒ�������¸�����������ծ��",
		"����Ҫ�ٵǸ������а�",
		"    ��ֻ���ڳ��д�40�죬ÿ�α���һ��������һ�졣һ��ʼ����ķ���",
		"ֻ�ܷ�100�����������������������������¼�������Ҫ����å��С͵�� ",
		"���֡�̰�١�ƭ�ӵȶ��Ƕ��£�����Ҫ���������ӵ���Ȼ�������跨����",
		"������",
		"    ���������ڳ��������VCD����˽�����Ĵ̼��Լ��������ʱ������",
		"�ĸ�Ц�¼���",
		"****************************************************************"
	};

	int len = sizeof(story) / sizeof(*story);

	for (int i = 0; i < len; i++)
	{
		if (i < 3 || i == len - 1)
		{
			cout << story[i] << endl;
			continue;
		}
		playTypewrite(story[i]);

	}
}

void Viewer::playTypewrite(string L_content)
{
	// �����ٶ�
	int speed = 10;

	for (unsigned int i = 0; i < L_content.length(); i++)
	{
		cout << L_content[i];

		if (L_content[i] == ' ') continue;
		// ��Ӵ�����Ч
		SoundController::getInstance()->playSound(10001);
		// ���ߺ���������Ϊ������
		Sleep(speed);
	}
	cout << endl;
}

void Viewer::showSysMenu()
{
	// 	�˵���
	vector<string> itemNames;
	itemNames.push_back("ϵͳ");
	itemNames.push_back("��Ҫ�ĳ���");
	itemNames.push_back("����");

	// ����ѡ�������д���
	switch (chooseMenuItem("��ӭ���������и����ǡ���", itemNames))
	{
	case 1:	// ϵͳ
		showSysMenuItem();
		break;
	case 2: // ��Ҫ�ĳ���
		break;
	case 3:	// ����
		break;
	default:
		break;
	}
}

void Viewer::showSysMenuItem()
{
	system("cls");
	// 	�˵���
	vector<string> itemNames;
	itemNames.push_back("����Ϸ");
	itemNames.push_back("�������а�");
	itemNames.push_back("��Ϸ����");
	itemNames.push_back("�˳�");

	switch (chooseMenuItem("ϵͳ�˵�", itemNames))
	{
	case 1:	// ����Ϸ
	{
		system("cls");
		GameCore::getInstance()->gameNewStart();
	}
	break;
	case 2: // �������а�
		break;
	case 3:	// ��Ϸ����
	{
		system("cls");
		showSysSettings();
	}
	break;
	case 4:	// �˳�
		break;
	default:
		break;
	}
}

int Viewer::chooseMenuItem(string menuName, vector<string>items)
{
	// �˵�����
	cout << menuName << endl;

	// �˵���ı���
	for (int i = 0; i < items.size(); i++)
	{
		cout << i + 1 << "." << items[i] << endl;
	}

	// �ȴ��������ѡ��
	cout << "����������ѡ��";
	int choice = 0;
	cin >> choice;

	return choice;
}

void Viewer::showSysSettings()
{
	// �˵���
	vector<string> itemNames;
	itemNames.push_back("����ڿ͹�����������");

	// ����Ǿ���״̬����ʾ��������������ǷǾ���״̬����ʾ�ر�����
	SoundController* soundController = SoundController::getInstance();
	bool isSilence = soundController->getSilence();
	if (isSilence)
	{
		itemNames.push_back("��������");
	}
	else
	{
		itemNames.push_back("�ر�����");
	}
	itemNames.push_back("����");

	// ����ѡ�������д���
	switch (chooseMenuItem("��Ϸ����", itemNames))
	{
	case 1:	// ����ڿ͹�����������
		break;
	case 2: // ��Ч����
	{
		system("cls");
		// �ȸı�״̬���ٿ�����ֹͣ��������
		soundController->setSilence(!isSilence);
		if (isSilence)
		{
			soundController->playBGM();
		}
		else
		{
			soundController->stopAll();
		}
		showSysSettings();
	}
	break;
	case 3:	// ����
	{
		system("cls");
		showSysMenuItem();
	}
	break;
	default:
		break;
	}
}

void Viewer::gameStartShow()
{
	// ��ʾ��Ϸ������
	if (!prt_mainView)
	{
		prt_mainView = new GameMainView();
	}

	prt_mainView->show();
}

void Viewer::gameEndShow()
{
	// ������ʾ

	// ���������
	if (prt_mainView)
	{
		delete prt_mainView;
		prt_mainView = nullptr;
	}
}