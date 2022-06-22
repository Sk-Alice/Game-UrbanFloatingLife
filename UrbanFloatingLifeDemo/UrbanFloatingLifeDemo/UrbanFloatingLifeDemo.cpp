#include <windows.h>	// 控制台
#include "GameController.h"
#include "GameInfoView.h"

using namespace std;

extern void setTitle(string title);
extern void setColor(char bgColor, char fgColor);
extern void setWinSize(int width, int height);

int main()
{
	// 控制台参数设置

	// 1.设置标题
	setTitle("都市浮生记");
	// 2.设置背景色和前景色
	setColor('1', 'F');
	// 3.设置窗体大小
	setWinSize(64, 38);

	// 游戏控制器单例对象
	GameController::getInstance()->game_start();

	system("pause");
	return 0;
}

// 设置标题
void setTitle(string title)
{
	stringstream cmd;	// 用来拼接字符串
	cmd << "title ";
	cmd << title;
	// 设置标题命令(command) title + 标题名称
	system(cmd.str().c_str());// system的参数为 const char*类型，c_str()以const char* 类型返回 string 内含的字符串
}

// 设置背景色和前景色
void setColor(char bgColor, char fgColor)
{
	stringstream cmd;
	cmd << "color ";
	cmd << bgColor;
	cmd << fgColor;
	// 设置背景命令: color + 背景色16进制数 + 前景色16进制数
	// 0-黑色 1-蓝色 2-绿色 3-浅绿色 4-红色 5-紫色 6-黄色 7-白色 8-灰色
	// 9-浅蓝色 10(A)-淡绿色 11(B)-前单绿色 12(C)-淡红色 13(D)-淡紫色 14(E)-淡红色 15(F)-亮白色
	system(cmd.str().c_str());
}

// 设置窗体大小
void setWinSize(int width, int height)
{
	stringstream cmd;
	cmd << "mode con ";
	cmd << "cols=" << width;
	cmd << "lines=" << height;
	// 设置窗体大小命令: mode con cols=... lines=... 
	system(cmd.str().c_str());// system的参数为 const char*类型，c_str()以const char* 类型返回 string 内含的字符串
}