#include "GameController.h"
#include "Viewer.h"
#include "SoundController.h"

GameController::GameController()
{

}

GameController::~GameController()
{

}

// 初始化单例对象
GameController* GameController::instance = nullptr;
GameController* GameController::getInstance()
{
	if (!instance)
	{
		instance = new GameController();
	}

	return instance;
}

void GameController::game_start()
{
	// 背景音乐的播放
	SoundController::getInstance()->playBGM();

	// 开场剧情动画的播放
	Viewer::getInstance()->showStory();

	// 系统菜单的展示
	Viewer::getInstance()->showSysMenu();
}

void GameController::game_end()
{

}
