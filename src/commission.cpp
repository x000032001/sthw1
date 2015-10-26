#include "commission.h"

#define VAR_HAHA
int cms_error_code = 0;

double retrieve(vector<tuple<int,int,int>> input)
{
	cms_error_code = 5;
	int tlock = 0,tstock = 0,tbarrel = 0;
	for( size_t i = 0 ; i < input.size() ; ++i )
	{
		// test terminate with -1 end
		if( i+1 == input.size() )
			if( get<0>(input[i]) != -1 )
			{
				cms_error_code = TERM_ERROR;
				puts("TERM_ERROR");
				return CMS_ERROR;
			}
			else
			{
				break;
			}
		
		int ilock,istock,ibarrel;
		tie(ilock,istock,ibarrel) = input[i]; // unpack
		if( 1 > ilock || ilock > 70 )
		{
			cms_error_code = LOCK_ERROR;
			return CMS_ERROR;
		}

		if( 1 > istock || istock > 80 )
		{
			cms_error_code = STOCK_ERROR;
			return CMS_ERROR;
		}

		if( 1 > ibarrel || ibarrel > 90 )
		{
			cms_error_code = BARREL_ERROR;
			return CMS_ERROR;
		}

		tlock += ilock;
		tstock += istock;
		tbarrel += ibarrel;
	}

	return countCms(tlock,tstock,tbarrel);
}


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

