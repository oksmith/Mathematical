// IsPrime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	long long x;	// this just gives us double the range
	std::cout << "Enter a number: " << std::endl;
	std::cin >> x; 

	bool prime = true;
	long long i = 2;

	long long y = x;
	while (i <= x / i)	// for optimisation purposes (prime factors can be no greater than x^0.5)
	{
		if (y%i == 0)
		{
			std::cout << "Prime factor found: " << i << std::endl;
			prime = false;
			y = y / i;
			//break; 
				// include this for optimisation (don't keep searching once prime has been found)
		}
		else
		{
			i += 1;
		}
	}
	std::cout << x << " is ";
	if (prime)
	{
		std::cout << "prime" << std::endl;
	}
	else
	{
		std::cout << "not prime" << std::endl;
	}
    return 0;
}

