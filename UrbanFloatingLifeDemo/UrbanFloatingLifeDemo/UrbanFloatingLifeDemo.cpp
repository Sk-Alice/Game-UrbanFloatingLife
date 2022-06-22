#include <windows.h>	// ����̨
#include "GameController.h"
#include "GameInfoView.h"

using namespace std;

extern void setTitle(string title);
extern void setColor(char bgColor, char fgColor);
extern void setWinSize(int width, int height);

int main()
{
	// ����̨��������

	// 1.���ñ���
	setTitle("���и�����");
	// 2.���ñ���ɫ��ǰ��ɫ
	setColor('1', 'F');
	// 3.���ô����С
	setWinSize(64, 38);

	// ��Ϸ��������������
	GameController::getInstance()->game_start();

	system("pause");
	return 0;
}

// ���ñ���
void setTitle(string title)
{
	stringstream cmd;	// ����ƴ���ַ���
	cmd << "title ";
	cmd << title;
	// ���ñ�������(command) title + ��������
	system(cmd.str().c_str());// system�Ĳ���Ϊ const char*���ͣ�c_str()��const char* ���ͷ��� string �ں����ַ���
}

// ���ñ���ɫ��ǰ��ɫ
void setColor(char bgColor, char fgColor)
{
	stringstream cmd;
	cmd << "color ";
	cmd << bgColor;
	cmd << fgColor;
	// ���ñ�������: color + ����ɫ16������ + ǰ��ɫ16������
	// 0-��ɫ 1-��ɫ 2-��ɫ 3-ǳ��ɫ 4-��ɫ 5-��ɫ 6-��ɫ 7-��ɫ 8-��ɫ
	// 9-ǳ��ɫ 10(A)-����ɫ 11(B)-ǰ����ɫ 12(C)-����ɫ 13(D)-����ɫ 14(E)-����ɫ 15(F)-����ɫ
	system(cmd.str().c_str());
}

// ���ô����С
void setWinSize(int width, int height)
{
	stringstream cmd;
	cmd << "mode con ";
	cmd << "cols=" << width;
	cmd << "lines=" << height;
	// ���ô����С����: mode con cols=... lines=... 
	system(cmd.str().c_str());// system�Ĳ���Ϊ const char*���ͣ�c_str()��const char* ���ͷ��� string �ں����ַ���
}