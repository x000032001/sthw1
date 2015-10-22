#include "commission.h"

TEST( Commission , Zero )
{
	ASSERT_EQ( 0 , countCms(0,0,0) );
}
