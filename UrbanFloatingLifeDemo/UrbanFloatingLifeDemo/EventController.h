#pragma once

/* ���ʱ��������� */

class EventController
{
private:
	static EventController* instance;

public:
	EventController();
	virtual ~EventController();

	static EventController* getInstance();

	// �����¼�����
	void loadingDate();

	// ���������ҵ���߼���Ӱ����Ʒ�۸�������ӵ����Ʒ����
	void playMessage(int id);
};

