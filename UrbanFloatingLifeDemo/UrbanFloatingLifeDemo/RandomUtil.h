#pragma once
/* ����������� */

class RandomUtil
{
private:

public:
	RandomUtil();
	virtual ~RandomUtil();

	// ָ����Χ�ڲ���һ���������
	static int getRandomInteger(int minRange, int maxRange);

	// ���ݸ��ʷ���һ�����--�Ƿ񴥷�
	static bool getProbabilityResult(int probability);
};

