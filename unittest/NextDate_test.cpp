#include "NextDate.h"

TEST( NextDate , MonthHas31Days )
{
	ASSERT_EQ( "2000 01 20" , nextDate("2000 01 19") );
	ASSERT_EQ( "2000 03 20" , nextDate("2000 03 19") );
	ASSERT_EQ( "2000 07 20" , nextDate("2000 07 19") );
	ASSERT_EQ( "2000 08 01" , nextDate("2000 07 31") );
	ASSERT_EQ( "2001 01 01" , nextDate("2000 12 31") );
}

TEST( NextDate , MonthHas30Days )
{
	ASSERT_EQ( "2000 04 02" , nextDate("2000 04 01") );
	ASSERT_EQ( "2000 06 24" , nextDate("2000 06 23") );
	ASSERT_EQ( "2000 12 01" , nextDate("2000 11 30") );
}

TEST( NextDate , Feb )
{
	ASSERT_EQ( "2000 02 02" , nextDate("2000 02 01") );
	ASSERT_EQ( "2000 02 29" , nextDate("2000 02 28") );
	ASSERT_EQ( "2000 03 01" , nextDate("2000 02 29") );
	ASSERT_EQ( "1900 03 01" , nextDate("1900 02 28") );
}
