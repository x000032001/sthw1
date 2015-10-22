#include "NextDate.h"

TEST( NextDate , MonthHas31Days )
{
	ASSERT_EQ( "2000 01 20" , nextDate("2000 01 19") );
	ASSERT_EQ( "2000 03 20" , nextDate("2000 03 19") );
	ASSERT_EQ( "2000 07 20" , nextDate("2000 07 19") );
	ASSERT_EQ( "2000 08 01" , nextDate("2000 07 31") );
	ASSERT_EQ( "2001 01 01" , nextDate("2000 12 31") );
}
