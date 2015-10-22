#include "NextDate.h"

TEST( NextDate , MonthHas31Days )
{
	ASSERT_EQ( "2000-01-20" , nextDate("2000-01-19") );
	ASSERT_EQ( "2000-03-20" , nextDate("2000-03-19") );
	ASSERT_EQ( "2000-09-20" , nextDate("2000-09-19") );
}
