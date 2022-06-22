#include "GameController.h"
#include "Viewer.h"
#include "SoundController.h"

GameController::GameController()
{

}

GameController::~GameController()
{

}

// ��ʼ����������
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
	// �������ֵĲ���
	SoundController::getInstance()->playBGM();

	// �������鶯���Ĳ���
	Viewer::getInstance()->showStory();

	// ϵͳ�˵���չʾ
	Viewer::getInstance()->showSysMenu();
}

void GameController::game_end()
{

}
