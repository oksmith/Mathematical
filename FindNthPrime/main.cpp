// FindNthPrime.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int primeVector[1000000];	
	// make this larger manually if you want a higher than 1 millionth prime

bool isPrime(int N)
{
	for (int i = 2; i <= sqrt(N); ++i)
	{
		if (N%i == 0)
			return false;	// found a prime factor
	}
	return true;
}

int main()
{
	int Max, N, m = 0;
	primeVector[0] = 1;

	cout << "Enter Maximum number to test to: " << endl;
	cin >> Max;

	cout << "Enter N (to find Nth prime): " << endl; 
	cin >> N;

	while (Max--)
	{
		if (!primeVector[N])	// keep going until we have found the Nth prime
			for (int i = primeVector[m] + 1; !primeVector[N]; ++i)
				// count up from the last prime found
			{
				if (isPrime(i))
				{
					primeVector[++m] = i;

				}
			}
		else
		{
			cout << primeVector[N] << endl;
			break;
		}
	}
	return 0;
}
