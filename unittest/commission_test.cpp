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
	for( int times = 0 ; times < 100 ; ++times )
	{
		vector<tuple<int,int,int>> dataSets;
		int sets = rand()%10+5;
		bool VALID_FLAG = true;
		for( int i = 0 ; i < sets ; ++i )
		{
			int l = num() , s = num() , b = num();
			if( !L1(l) || !S1(s) || !B1(b) )
				VALID_FLAG = false;
			dataSets.emplace_back(make_tuple(l,s,b));
		}
		if( times <= 90 )
			dataSets.emplace_back(make_tuple(-1,0,0));
		else
			VALID_FLAG = false;

		if( VALID_FLAG )
		{
			double result = retrieve(dataSets);
			ASSERT_TRUE( CMS_ERROR < result ) << "Run: " << times << "\tResult = " << result << "\tCode = " << cms_error_code << endl;
		}
		else
		{
			double result = retrieve(dataSets);
			ASSERT_TRUE( CMS_ERROR >= result ) << "Run: " << times << "\tResult = " << result << "\tCode = " << cms_error_code << endl;
		}
	}
}




