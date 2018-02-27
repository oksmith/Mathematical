// FibMultiplesCount.cpp : Program to find the number of multiples of an integer x in the Fibonnacci 
//						   sequence (starting with 1, 2, 3, 5, 8, ...) up to a specified integer n. 

#include "stdafx.h"
#include <iostream>

int main()
{
	int x = 1;
	int n = 1;
	std::cout << "Enter the integer to count multiples of: " << std::endl;
	// for example, entering x=2 means we will count all even integers
	std::cin >> x;
	std::cout << "Enter the maximum value of the Fibonnacci sequence: " << std::endl;
	std::cin >> n;

	int a = 1;
	int b = 2;
	int num = 0;
	int c = a + b;

	while (b <= n)
	{
		if (b%x == 0)
		{
			num+=1;
		}
		a = b;
		b = c;
		c = a + b;
	}

	std::cout << "The number of multiples of " << x << " in the Fibonnacci sequence up to " <<
		n << " is " << std::endl;
	std::cout << num << std::endl;
	return 0;
}
