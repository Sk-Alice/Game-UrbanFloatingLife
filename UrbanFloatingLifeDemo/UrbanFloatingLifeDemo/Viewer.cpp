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

// 初始化单例对象
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
	// 获取故事内容
	string story[] = {
		"****************************************************************",
		"*                    《都市浮生记》的故事                      *",
		"****************************************************************",
		"    您扮演一位从外地到城市谋生的青年。开始，您只有2000元钱。并且",
		"还欠村长(一个流氓头子)5500的债务。这些债务每天的利息高达10%。  ",
		"如果不及时还清，村长会叫在市里的老乡们来扁您，您可能牺牲在市区街",
		"头。您决定在市区地铁各黑市倒卖各种物品来发财致富，不仅还掉债务，",
		"而且要荣登富人排行榜。",
		"    您只能在城市呆40天，每次奔走一个黑市算一天。一开始您租的房子",
		"只能放100个东西。您会在市区遭遇到各种事件，您需要与流氓、小偷、 ",
		"凶手、贪官、骗子等斗智斗勇，还需要在市区恶劣的自然环境下设法生存",
		"下来。",
		"    您将体验在城市买盗版VCD和走私汽车的刺激以及我们这个时代才有",
		"的搞笑事件。",
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
	// 打字速度
	int speed = 10;

	for (unsigned int i = 0; i < L_content.length(); i++)
	{
		cout << L_content[i];

		if (L_content[i] == ' ') continue;
		// 添加打字音效
		SoundController::getInstance()->playSound(10001);
		// 休眠函数，参数为毫秒数
		Sleep(speed);
	}
	cout << endl;
}

void Viewer::showSysMenu()
{
	// 	菜单项
	vector<string> itemNames;
	itemNames.push_back("系统");
	itemNames.push_back("重要的场景");
	itemNames.push_back("帮助");

	// 根据选择结果进行处理
	switch (chooseMenuItem("欢迎来到《都市浮生记》！", itemNames))
	{
	case 1:	// 系统
		showSysMenuItem();
		break;
	case 2: // 重要的场景
		break;
	case 3:	// 帮助
		break;
	default:
		break;
	}
}

void Viewer::showSysMenuItem()
{
	system("cls");
	// 	菜单项
	vector<string> itemNames;
	itemNames.push_back("新游戏");
	itemNames.push_back("高手排行榜");
	itemNames.push_back("游戏设置");
	itemNames.push_back("退出");

	switch (chooseMenuItem("系统菜单", itemNames))
	{
	case 1:	// 新游戏
	{
		system("cls");
		GameCore::getInstance()->gameNewStart();
	}
	break;
	case 2: // 高手排行榜
		break;
	case 3:	// 游戏设置
	{
		system("cls");
		showSysSettings();
	}
	break;
	case 4:	// 退出
		break;
	default:
		break;
	}
}

int Viewer::chooseMenuItem(string menuName, vector<string>items)
{
	// 菜单名称
	cout << menuName << endl;

	// 菜单项的遍历
	for (int i = 0; i < items.size(); i++)
	{
		cout << i + 1 << "." << items[i] << endl;
	}

	// 等待玩家输入选择
	cout << "请做出您的选择：";
	int choice = 0;
	cin >> choice;

	return choice;
}

void Viewer::showSysSettings()
{
	// 菜单项
	vector<string> itemNames;
	itemNames.push_back("允许黑客攻击银行网络");

	// 如果是静音状态，显示开启声音；如果是非静音状态，显示关闭声音
	SoundController* soundController = SoundController::getInstance();
	bool isSilence = soundController->getSilence();
	if (isSilence)
	{
		itemNames.push_back("开启声音");
	}
	else
	{
		itemNames.push_back("关闭声音");
	}
	itemNames.push_back("返回");

	// 根据选择结果进行处理
	switch (chooseMenuItem("游戏设置", itemNames))
	{
	case 1:	// 允许黑客攻击银行网络
		break;
	case 2: // 音效设置
	{
		system("cls");
		// 先改变状态，再开启或停止播放声音
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
	case 3:	// 返回
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
	// 显示游戏主界面
	if (!prt_mainView)
	{
		prt_mainView = new GameMainView();
	}

	prt_mainView->show();
}

void Viewer::gameEndShow()
{
	// 评价显示

	// 销毁主面板
	if (prt_mainView)
	{
		delete prt_mainView;
		prt_mainView = nullptr;
	}
}