#include "commission.h"

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

