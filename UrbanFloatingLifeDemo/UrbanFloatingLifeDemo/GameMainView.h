#pragma once
#include "GameInfoView.h"

/* ��Ϸ������ */

class GameMainView : public GameInfoView
{
private:
	// ��Ϸ����ѡ��
	void showFuncChoice();

public:
	GameMainView();
	~GameMainView();

	void show() override;
};

