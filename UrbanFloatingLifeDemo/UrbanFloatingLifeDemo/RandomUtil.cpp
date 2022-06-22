#include <cstdlib>		// 随机数
#include <ctime>		// time() 随机种子
#include "RandomUtil.h"

RandomUtil::RandomUtil()
{

}

RandomUtil::~RandomUtil()
{

}

// 表示是否产生过随机种子
static bool flag = false;
int RandomUtil::getRandomInteger(int minRange, int maxRange)
{
	// 随机种子
	if (!flag)
	{
		srand((unsigned int)time(NULL));
		flag = true;
	}

	// 产生[minRange,maxRange]的一个随机数
	return rand() % (maxRange - minRange) + minRange;
}

bool RandomUtil::getProbabilityResult(int probability)
{
	// probability 在0~100之间，扩大100倍后，
	// 与在0~10000之间随机产生的数比较，大于等于成功触发，反之
	return probability * 100 >= RandomUtil::getRandomInteger(0, 10000);
}