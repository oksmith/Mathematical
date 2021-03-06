﻿// CollatzSequence.cpp : Program to simulate the Collatz sequence until its termination at 1. 
//		It then counts the length of the sequence.

#include "stdafx.h"
#include <iostream>
#include <vector>

unsigned long long step(unsigned long long n)		// an individual step of the sequence
{
	if ((n % 2) == 0)
	{
		return n / 2;
	}
	return 3 * n + 1;
}

int main()
{	
	std::cout << "Enter the maximum starting point for the sequence, x: " << std::endl;
	unsigned long long x;
	std::cin >> x;	// user defines the maximum "starting value"
	// std::vector<int> length;

	std::vector< unsigned long long> stepVec (x-1,1);
		// note that stepVec will end up being indexed from (0, 1, ..., x-1)

	int maxSteps = 0;
	int startNumber = 0;
	unsigned long long check;

	int repeat = 2;

	for (int i = 2; i <= x; i++)
	{
		int steps = 1;
			// tests for repeat sequences
		check = i;
			// this will be the sequence
		while (check != 1 && repeat >=i)
		{
			check = step(check);
			repeat++;
			steps++;
		}
		if (check == 1)	// ie the while loop terminated because we reached 1
		{
			stepVec[i-2] = steps;	//eg index i=2 corresponds to the 0 index of stepVec
			if (steps > maxSteps)
			{
				maxSteps = steps;
				startNumber = i;
			}
		}
		else	//ie the while loop terminated because we reached a familiar number
		{
			stepVec[i-2] = steps + stepVec[repeat-2];
			if (steps + stepVec[repeat-2] > maxSteps)
			{
				maxSteps = steps + stepVec[repeat-2];
				startNumber = i;
			}
		}	
	}

	// now state our final sequence length and starting value
	std::wcout << "Max sequence length is " << maxSteps <<
		" which occurs with starting value " << startNumber << std::endl;

    return 0;

	// UNPROVEN CONJECTURE: Collatz sequences always end in 1. Therefore the while loop will always come to an end.
	//	How might one prove this? A quick attempt at proof by contradiction doesn't yield much.
}
