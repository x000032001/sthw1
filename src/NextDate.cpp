#include "NextDate.h"

#include <iomanip>
#include <sstream>
using namespace std;

string nextDate(string now)
{
	stringstream ss(now);
	int year ,month ,day;
	ss >> year >> month >> day;

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

	stringstream oss;
	oss <<  year << " " 
		<< setfill('0') << setw(2) << month << " "
		<< setfill('0') << setw(2) << day;
	return oss.str();
}
