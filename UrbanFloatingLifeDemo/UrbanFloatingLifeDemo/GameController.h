#pragma once
/* 游戏控制器 */

class GameController
{
private:
	static GameController* instance;

public:
	GameController();
	virtual ~GameController();

	// 向系统提供实例 - 获取单例对象
	static GameController* getInstance();
	// 游戏开始
	void game_start();
	// 游戏结束
	void game_end();
};
