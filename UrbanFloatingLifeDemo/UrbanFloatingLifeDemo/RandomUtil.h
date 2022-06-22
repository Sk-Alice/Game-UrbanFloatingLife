#pragma once
/* 随机数工具类 */

class RandomUtil
{
private:

public:
	RandomUtil();
	virtual ~RandomUtil();

	// 指定范围内产生一个随机整数
	static int getRandomInteger(int minRange, int maxRange);

	// 根据概率返回一个结果--是否触发
	static bool getProbabilityResult(int probability);
};

