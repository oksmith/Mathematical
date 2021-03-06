// PalindromeProducts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

bool testPalindrome(int z);

int main()
{
	std::cout << "Enter number of digits: " << std::endl;
	int digits;
	std::cin >> digits;

	int maxDigits(int digits);
	int maxNum = maxDigits(digits);		// for example digits=3, maxNum=999.

	int x = maxNum, y=maxNum;
	int z;
	int max = 0;
	bool flag = false;

	for (x; x >= 100; x--)
	{
		for (y=maxNum; y >= x; y--)	// we want to find the largest palindrome, so we'll count down from 999 to 100
									// in each of x and y
		{
			z = x * y;
			if (testPalindrome(z)) 
			{ 
				max = (z > max) ? z : max;
			} 
		}
	}

	std::cout << "The largest palindrome of " << digits << " numbers is " << max << std::endl;

    return 0;
}

