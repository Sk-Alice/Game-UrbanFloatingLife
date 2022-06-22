#pragma once
/* 视图类 */

#include <string>
#include <vector>
#include "GameMainView.h"

using namespace std;

class Viewer
{
private:
	// 创建视图类单例对象
	static Viewer* instance;

	// 播放打字动画 -- 参数 string 表示每一行的内容
	void playTypewrite(string L_content);

	// 显示系统菜单项选择
	void showSysMenuItem();

	// 系统设置菜单
	void showSysSettings();

	// 游戏主面板
	GameMainView* prt_mainView;
public:
	Viewer();
	virtual ~Viewer();

	// 向系统提供实例 - 获取单例对象
	static Viewer* getInstance();

	// 播放开场剧情的动画
	void showStory();

	// 系统菜单的展示
	void showSysMenu();

	// 游戏开启显示
	void gameStartShow();
	// 游戏结束显示
	void gameEndShow();

	/*
		封装一个菜单选择列表
		参数一：菜单名称  参数二：菜单项  返回值：玩家选择的菜单值编号
	*/
	static int chooseMenuItem(string menuName, vector<string> items);

};

