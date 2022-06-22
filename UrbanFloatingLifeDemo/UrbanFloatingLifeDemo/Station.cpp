#include "Station.h"

Station::Station()
{
	prt_id = 0;
	prt_market = nullptr;
}

Station::~Station()
{
	if (prt_market)
	{
		delete prt_market;
		prt_market = nullptr;
	}
}

BlackMarket* Station::getMarket()
{
	if (!prt_market)
	{
		prt_market = new BlackMarket();
		prt_market->setId(prt_id);
		prt_market->setName(prt_name);
	}
	return prt_market;
}