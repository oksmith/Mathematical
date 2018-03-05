#include "stdafx.h"
#include <cmath>

int maxDigits(int digits) 
{
	int maxNum = 0;
	while (digits != 0)
	{
		maxNum += 9 * pow(10,digits-1);
		digits -= 1;
	}
	return maxNum;
}