// CountingSundays.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

using namespace std;
int getStartDay(int startYear);
int monthDays(int month, int year);

int main()
{
	cout << "Start year: " << endl;
	int startYear;
	cin >> startYear;
	cout << "End year: " << endl;
	int endYear;
	cin >> endYear;

	int startDay = getStartDay(startYear);	// first day of the year of start year

	int day = startDay;
	int count=0;

	if (day == 0) { count = 1; }	// we want to include the 1st January (startYear) if it is a Sunday

	for (int year = startYear; year <= endYear; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			day = day + monthDays(month,year);
				// first day of the next month
			if (day % 7 == 0) { count++; }
		}
	}

	if (day % 7 == 0) { count = count - 1; }
		// we have finished the loop on 1st January (endYear+1). 
		// if this day is a Sunday, then we've counted one too many

	cout << "Number of Sundays that fall on 1st of month between start year and end year: " << count << endl;

    return 0;
}

