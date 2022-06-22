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

	// 显示时间
	showDay();
	// 显示随机事件
	showEvent();
	// 显示角色信息
	showRoleInfo();
}

void GameInfoView::showDay()
{
	if (prt_currDay == 1)
	{
		cout << "您开启了浮生之旅！" << endl;
	}
	cout << "第" << prt_currDay << "天/" << prt_maxDay << "天" << endl;
}

void GameInfoView::showEvent()
{
	Message* message = GameWorld::getInstance()->getCurrMessage();
	if (!message) return;
	int width = 62;
	// 第一行分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;

	// 影响物品价格的消息
	cout << "都市新闻" << endl;

	// 标题分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;

	// 打印消息内容
	cout << message->getContent() << endl;

	// 最后一行分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl;


}

void GameInfoView::showRoleInfo()
{
	// 绘制玩家信息边框
	int width = 62;
	// 第一行分隔符
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;

	// 显示内容
	vector<string> infos;
	infos.push_back("玩家信息：");
	infos.push_back(showFormatForRoleProp(1, "现金", prt_role->getCash(), "元"));
	infos.push_back(showFormatForRoleProp(2, "存款", prt_role->getDeposit(), "元"));
	infos.push_back(showFormatForRoleProp(3, "欠债", prt_role->getDebt(), "元"));
	infos.push_back(showFormatForRoleProp(4, "健康", prt_role->getHp()));
	infos.push_back(showFormatForRoleProp(5, "名声", prt_role->getFame()));

	for (string content : infos)
	{
		cout << "*";
		// 打印left个空格
		int left = 2;
		for (int i = 0; i < left; i++)
		{
			cout << " ";
		}

		// 打印内容
		cout << content;

		// 打印右侧空格 = 总宽度 - 内容长度 - 前后*占的两个字符 - 前面的空格数left
		size_t right = width - content.length();
		for (int i = 0; i < right - 2 - left; i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}

	// 最后一行分隔符
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
	sstream << name << "： ";
	sstream << setw(10) << money << "  ";
	sstream << unit;

	return sstream.str();
}

