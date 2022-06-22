#pragma once
#include <iostream>
#include <string>

using namespace std;

/* 游戏场景s数据模型 */

class GamePlace
{
private:
	int prt_id;
	string prt_name;

public:
	GamePlace();
	virtual ~GamePlace();

	int getId() { return prt_id; }
	void setId(int id) { prt_id = id; }
	string getName() { return prt_name; }
	void setName(string name) { prt_name = name; }

};

