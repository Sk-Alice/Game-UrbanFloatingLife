#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>

#include "GameRole.h"

using namespace std;
/* 游戏玩家信息显示类 */

class GameInfoView
{
private:
	// 显示数据：当前天数
	int prt_currDay;
	// 显示数据：最大天数
	int prt_maxDay;
	// 显示时间
	void showDay();

	// 显示随机事件
	void showEvent();

	// 显示数据：角色属性展示
	GameRole* prt_role;

	// 显示玩家信息
	void showRoleInfo();

	// 封装：角色属性项显示格式
	string showFormatForRoleProp(int id, string name, int money, string unit = "");

protected:
	// 显示
	virtual void show();

public:
	GameInfoView();
	virtual ~GameInfoView();

};

