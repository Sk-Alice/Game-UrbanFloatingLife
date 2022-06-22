#pragma once
#include <vector>
#include <map>
#include "GamePlace.h"
#include "Station.h"
#include "GameRole.h"
#include "Message.h"

using namespace std;

/* ��Ϸ��������ģ�� */

class GameWorld
{
private:
	// ���õ���ģʽ
	static GameWorld* instance;

	// ��Ϸ��ǰ��ʱ��
	int prt_currDay;
	// ��Ϸ�����ʱ��
	int prt_maxDay;

	// ��Ϸ��ɫ
	GameRole* prt_role;

	// ��Ϸ�����ļ���
	vector<GamePlace*> prt_places;

	// ��Ϸ��Ʒ
	map<int, GameGoods*>prt_goods;

	// ����վ�б�
	vector<Station*> prt_stations;

	// ��¼��Ϣ
	map<int, Message*> prt_messages;

	// ��¼��ǰ��������Ϣ
	Message* prt_currMessage;
public:
	GameWorld();
	virtual ~GameWorld();

	// ��ϵͳ�ṩʵ�� - ��ȡ��������
	static GameWorld* getInstance();

	// ��ȡ��ǰʱ��
	int getCurrDay();
	// ���ĵ�ǰʱ��
	void setCurrDay(int day);
	// ��ȡ���ʱ��
	int getMaxDay();

	// ��ȡ��Ϸ��ɫʵ��
	GameRole* getGameRole();

	// ��ȡ��Ϸ��������
	vector<GamePlace*>* getGamePlaces() { return &prt_places; }

	// ��ȡ���е���Ʒ
	map<int, GameGoods*>* getAllGoods() { return &prt_goods; }

	// ��ȡ����վ�б�
	vector<Station*>* getStations() { return &prt_stations; }

	// ��ȡ������Ϣ��¼
	map<int, Message*>* getMessages() { return &prt_messages; }

	Message* getCurrMessage() { return prt_currMessage; }
	void setCurrMessage(Message* currMessage) { prt_currMessage = currMessage; }
};
