#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>

#include "GameRole.h"

using namespace std;
/* ��Ϸ�����Ϣ��ʾ�� */

class GameInfoView
{
private:
	// ��ʾ���ݣ���ǰ����
	int prt_currDay;
	// ��ʾ���ݣ��������
	int prt_maxDay;
	// ��ʾʱ��
	void showDay();

	// ��ʾ����¼�
	void showEvent();

	// ��ʾ���ݣ���ɫ����չʾ
	GameRole* prt_role;

	// ��ʾ�����Ϣ
	void showRoleInfo();

	// ��װ����ɫ��������ʾ��ʽ
	string showFormatForRoleProp(int id, string name, int money, string unit = "");

protected:
	// ��ʾ
	virtual void show();

public:
	GameInfoView();
	virtual ~GameInfoView();

};

