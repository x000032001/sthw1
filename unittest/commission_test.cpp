#include "commission.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

TEST( Commission , Zero )
{
	ASSERT_EQ( 0 , countCms(0,0,0) );
}

TEST( Commission , MoreThan1800 )
{
	ASSERT_EQ( 260 , countCms(0,0,80) );
}

TEST( Commission , MoreThan1000 )
{
	ASSERT_EQ( 103.75 , countCms(0,0,41) );
	ASSERT_EQ( 175 , countCms(0,0,60) );
}

TEST( Commission , LessThan1000 )
{
	ASSERT_EQ( 50 , countCms(0,0,20) );
}

bool L1(int a){ return 1<=a && a<=70; }
bool S1(int a){ return 1<=a && a<=80; }
bool B1(int a){ return 1<=a && a<=90; }

bool L2(int a){ return a==-1; }
bool L3(int a){ return a==0||a<-1; }
bool L4(int a){ return a>70; }
bool S2(int a){ return a<1; }
bool S3(int a){ return a>80; }
bool B2(int a){ return a<1; }
bool B3(int a){ return a>90; }

int num(){ return rand()%100-5; }

TEST( Commission , EquivalenceClass )
{
	srand(time(NULL));
	for( int times = 0 ; times < 100000 ; ++times )
	{
		vector<tuple<int,int,int>> dataSets;
		int sets = rand()%10+5;
		bool VALID_FLAG = true;
		bool TERM_FLAG = false;
		bool LOCK_ERR_FLAG = false ,STOCK_ERR_FLAG = false ,BARREL_ERR_FLAG = false;
		for( int i = 0 ; i < sets ; ++i )
		{
			int l = num() , s = num() , b = num();
			if( !L1(l) || !S1(s) || !B1(b) )
				VALID_FLAG = false;
			if( L2(l) ) TERM_FLAG = true;
			if( L3(l) || L4(l) ) LOCK_ERR_FLAG = true;
			if( S2(s) || S3(s) ) STOCK_ERR_FLAG = true;
			if( B2(b) || B3(b) ) BARREL_ERR_FLAG = true;

			dataSets.emplace_back(make_tuple(l,s,b));

			if( TERM_FLAG ) break;
		}

		//add terminator
		if( !TERM_FLAG )
			if( num() % 4 != 3 ) // 75% chance
			{
				dataSets.emplace_back(make_tuple(-1,0,0));
				TERM_FLAG = true;
			}
			else
				VALID_FLAG = false;

		// for any error, result will be invalid
		if( LOCK_ERR_FLAG || STOCK_ERR_FLAG || BARREL_ERR_FLAG || !TERM_FLAG )
			VALID_FLAG = false;

		double result = retrieve(dataSets);
		if( VALID_FLAG == true )
		{
			ASSERT_TRUE( 0 <= result ) << "Result is Valid but return error";
		}
		else
		{
			// error code must match the flag
			switch(cms_error_code) {
				case TERM_ERROR:
					ASSERT_TRUE(!TERM_FLAG);
					break;
				case LOCK_ERROR:
					ASSERT_TRUE(LOCK_ERR_FLAG);
					break;
				case STOCK_ERROR:
					ASSERT_TRUE(STOCK_ERR_FLAG);
					break;
				case BARREL_ERROR:
					ASSERT_TRUE(BARREL_ERR_FLAG);
					break;
				case OK:
					break;
				default:
					ASSERT_TRUE(false) << "Fatel Error ,Code = " << cms_error_code << endl;
			}
		}
	}
}




