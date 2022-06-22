#include <cstdlib>		// �����
#include <ctime>		// time() �������
#include "RandomUtil.h"

RandomUtil::RandomUtil()
{

}

RandomUtil::~RandomUtil()
{

}

// ��ʾ�Ƿ�������������
static bool flag = false;
int RandomUtil::getRandomInteger(int minRange, int maxRange)
{
	// �������
	if (!flag)
	{
		srand((unsigned int)time(NULL));
		flag = true;
	}

	// ����[minRange,maxRange]��һ�������
	return rand() % (maxRange - minRange) + minRange;
}

bool RandomUtil::getProbabilityResult(int probability)
{
	// probability ��0~100֮�䣬����100����
	// ����0~10000֮��������������Ƚϣ����ڵ��ڳɹ���������֮
	return probability * 100 >= RandomUtil::getRandomInteger(0, 10000);
}