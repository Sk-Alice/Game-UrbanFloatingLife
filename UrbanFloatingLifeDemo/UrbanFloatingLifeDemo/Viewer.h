#pragma once
/* ��ͼ�� */

#include <string>
#include <vector>
#include "GameMainView.h"

using namespace std;

class Viewer
{
private:
	// ������ͼ�൥������
	static Viewer* instance;

	// ���Ŵ��ֶ��� -- ���� string ��ʾÿһ�е�����
	void playTypewrite(string L_content);

	// ��ʾϵͳ�˵���ѡ��
	void showSysMenuItem();

	// ϵͳ���ò˵�
	void showSysSettings();

	// ��Ϸ�����
	GameMainView* prt_mainView;
public:
	Viewer();
	virtual ~Viewer();

	// ��ϵͳ�ṩʵ�� - ��ȡ��������
	static Viewer* getInstance();

	// ���ſ�������Ķ���
	void showStory();

	// ϵͳ�˵���չʾ
	void showSysMenu();

	// ��Ϸ������ʾ
	void gameStartShow();
	// ��Ϸ������ʾ
	void gameEndShow();

	/*
		��װһ���˵�ѡ���б�
		����һ���˵�����  ���������˵���  ����ֵ�����ѡ��Ĳ˵�ֵ���
	*/
	static int chooseMenuItem(string menuName, vector<string> items);

};

