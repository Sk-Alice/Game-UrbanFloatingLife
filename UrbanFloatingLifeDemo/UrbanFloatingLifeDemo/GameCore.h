#pragma once
#include "BlackMarket.h"
/* 游戏核心 -- 对游戏的进程控制 */

class GameCore
{
private:
	static GameCore* instance;

	// 游戏的状态
	bool prt_gameState;

	// 逻辑刷新
	void LogicUpdate();

	// 显示刷新
	void showUpdate();

	// 更新指定黑市的商品列表
	void updateMarketList(BlackMarket* market);
public:
	GameCore();
	virtual ~GameCore();

	static GameCore* getInstance();
	void gameNewStart();
	void game_end();
};

