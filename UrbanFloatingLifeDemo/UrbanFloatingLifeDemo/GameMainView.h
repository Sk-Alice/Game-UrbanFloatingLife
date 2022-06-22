#pragma once
#include "GameInfoView.h"

/* 游戏主界面 */

class GameMainView : public GameInfoView
{
private:
	// 游戏功能选择
	void showFuncChoice();

public:
	GameMainView();
	~GameMainView();

	void show() override;
};

