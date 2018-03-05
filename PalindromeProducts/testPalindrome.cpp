#include "stdafx.h"

bool testPalindrome(int z)
{
	// we reverse the number z and then test if (z==zReversed)
	int zReversed = 0;
	int zTemporary = z;
	while (zTemporary != 0)
	{
		zReversed = 10*zReversed + zTemporary % 10;
		zTemporary /= 10;
	}
	return z == zReversed;

	// OLD CODE (first attempt - doesn't work). 

	//// express z as a*10^6 + b*10^5 + c*10^4 + d*10^3 + e*10^2 + f*10^1 + g where 
	//// a,b,c,d,e are integers between 0 and 9
	//int G = (z % 10);								int g = G;
	//int F = ((z % 100) - G);						int f = F / 10;	// single digit f
	//int E = ((z % 1000) - F - G);					int e = E / 100;
	//int D = ((z % 10000) - E - F - G);				int d = D / 1000;
	//int C = ((z % 100000) - D - E - F - G);			int c = C / 10000;
	//int B = ((z % 1000000) - C - D - E - F - G);	int b = B / 100000;
	//int A = z - B - C - D - E - F - G;				int a = A / 1000000;

	//// for the purposes of this program, z can only be between 100^2 and 999^2
	//if (a != 0) 
	//{
	//	if ((a == g) && (b == f) && (c == e)) { return 1; } 
	//	else { return 0; }
	//}
	//else // so a==0
	//{
	//	if (b != 0)
	//	{
	//		if ((b == g) && (c == f) && (d == e)) { return 1; } 
	//		else { return 0; }
	//	}
	//	else // so a==0 and b==0
	//	{
	//		if ((c == g) && (d == f)) { return 1; } 
	//		else { return 0; }
	//	}
	//}
}