#pragma once

/* 随机时间控制器类 */

class EventController
{
private:
	static EventController* instance;

public:
	EventController();
	virtual ~EventController();

	static EventController* getInstance();

	// 加载事件数据
	void loadingDate();

	// 处理触发后的业务逻辑：影响物品价格或者玩家拥有物品数量
	void playMessage(int id);
};

