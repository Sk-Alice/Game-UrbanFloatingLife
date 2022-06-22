#pragma once
#include <vector>
#include <map>
#include "GamePlace.h"
#include "Station.h"
#include "GameRole.h"
#include "Message.h"

using namespace std;

/* 游戏世界数据模型 */

class GameWorld
{
private:
	// 采用单例模式
	static GameWorld* instance;

	// 游戏当前的时间
	int prt_currDay;
	// 游戏的最大时间
	int prt_maxDay;

	// 游戏角色
	GameRole* prt_role;

	// 游戏场景的集合
	vector<GamePlace*> prt_places;

	// 游戏物品
	map<int, GameGoods*>prt_goods;

	// 地铁站列表
	vector<Station*> prt_stations;

	// 记录消息
	map<int, Message*> prt_messages;

	// 记录当前触发的消息
	Message* prt_currMessage;
public:
	GameWorld();
	virtual ~GameWorld();

	// 向系统提供实例 - 获取单例对象
	static GameWorld* getInstance();

	// 获取当前时间
	int getCurrDay();
	// 更改当前时间
	void setCurrDay(int day);
	// 获取最大时间
	int getMaxDay();

	// 获取游戏角色实例
	GameRole* getGameRole();

	// 获取游戏场景集合
	vector<GamePlace*>* getGamePlaces() { return &prt_places; }

	// 获取所有的物品
	map<int, GameGoods*>* getAllGoods() { return &prt_goods; }

	// 获取地铁站列表
	vector<Station*>* getStations() { return &prt_stations; }

	// 获取所有消息记录
	map<int, Message*>* getMessages() { return &prt_messages; }

	Message* getCurrMessage() { return prt_currMessage; }
	void setCurrMessage(Message* currMessage) { prt_currMessage = currMessage; }
};
