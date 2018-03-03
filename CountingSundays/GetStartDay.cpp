#include "stdafx.h"
#include <iostream>
using namespace std;
int monthDays(int month, int year);

int getStartDay(int startYear)
{
	int day = 1;		// assume 1 January is Monday for now, we'll adjust at the end
	int startDay;

	if (startYear >= 1900)
	{
		for (int year = 1900; year < startYear; year++)
		{
			for (int month = 1; month <= 12; month++)
			{
				day = day + monthDays(month, year);
				// first day of the next month
			}
		}
		day = day % 7;
		// now we have a value for day which represents the 1st January (startYear)
		startDay = day;
	}
	else
	{
		for (int year = startYear; year < 1900; year++)
		{
			for (int month = 1; month <= 12; month++)
			{
				day = day + monthDays(month, year);
				// first day of the next month
			}
		}
		// we now have a value for day which represents 1st January 1900 (year after loop ends)
		// Adjusting for the fact 1st Jan 1900 = Monday:
		day = day % 7;
		int difference = day-1;
			// this is the number of days ahead we have been working the whole time, by
			// assuming 1st Jan (startYear) was a Monday
		startDay=(difference == 0 || difference==1) ? (1-difference) : startDay = 8 - difference;
			// we have now adjusted startDay correctly. It is also an integer between 0 and 6.
	}

	//// FIX
	//	int compFourYrs = (startYear - 1901) / 4;	// integer number of quadruple years between startYear and 1901
	//												// used to determine number of leap years to allow for
	//	day = 1 + 365 + (365 * 3 + 366)*compFourYrs + 365 * (startYear - 1901 - 4 * compFourYrs);
	//		// read as "day = Monday + 365 days (the year 1900) + (each complete quadruple year) + (remainder)"
	//	day = day % 7;
	//	if (day < 0) { day = day + 7; }
	//		// to put the start day into an integer mod 7 (1=Monday, 2=Tuesday etc and 0=Sunday)

	//// Now let's just output to console for the reader's interest
	
	switch (startDay)
	{
	case 0: cout << "Start day of start year: " << "Sunday" << endl;
		break;
	case 1: cout << "Start day of start year: " << "Monday" << endl;
		break;
	case 2: cout << "Start day of start year: " << "Tuesday" << endl;
		break;
	case 3: cout << "Start day of start year: " << "Wednesday" << endl;
		break;
	case 4: cout << "Start day of start year: " << "Thursday" << endl;
		break;
	case 5: cout << "Start day of start year: " << "Friday" << endl;
		break;
	case 6: cout << "Start day of start year: " << "Saturday" << endl;
		break;
	}

	return startDay;
}