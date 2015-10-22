#include "NextDate.h"

#include <iomanip>
#include <sstream>
using namespace std;

string nextDate(string now)
{
	stringstream ss(now);
	int year ,month ,day;
	ss >> year >> month >> day;

	// 31 days
	if( month == 1 || month == 3
	||  month == 5 || month == 7
	||  month == 8 || month == 10
	||  month == 12 )
	{
		if( day < 31 )
		{
			day++;
		}
		else if( day == 31 )
		{
			day = 1;
			month++;
			if( month == 13 )
			{
				month = 1;
				year++;
			}
		}
		else
		{
			return "error";
		}
	}

	// 30 days
	if( month == 4 || month == 6
	||  month == 9 || month == 11 )
	{
		if( day < 30 )
		{
			day++;
		}
		else if( day == 30 )
		{
			day = 1;
			month++;
		}
		else
		{
			return "error";
		}
	}

	if( month == 2 )
	{
		if( day < 28 )
		{
			day++;
		}
		else if( day == 28 )
		{
			if( (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 )
			{
				day++;
			}
			else
			{
				day = 1;
				month = 3;
			}
		}
		else if( day == 29 )
		{
			if( (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 )
			{
				day = 1;
				month = 3;
			}
			else
			{
				return "error";
			}
		}
		else
		{
			return "error";
		}
	}

	stringstream oss;
	oss <<  year << " " 
		<< setfill('0') << setw(2) << month << " "
		<< setfill('0') << setw(2) << day;
	return oss.str();
}
