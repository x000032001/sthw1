#include "commission.h"

double countCms(int locks,int stocks,int barrels)
{
	const double lockPrice = 45;
	const double stockPrice = 30;
	const double barrelPrice = 25;

	double sales =   locks * lockPrice 
				   + stocks * stockPrice
				   + barrels * barrelPrice;

	double ret = 0;
	if( sales > 1800 )
	{
		ret += 0.1 * 1000;
		ret += 0.15 * 800;
		ret += 0.2 * (sales-1800);	
	}
	else if( sales > 1000 )
	{
		ret += 0.1 * 1000;
		ret += 0.15 * (sales-1000);
	}
	else
	{
		ret += 0.1 * sales;
	}

	return ret;
}
