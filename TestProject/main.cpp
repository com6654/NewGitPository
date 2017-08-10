#include <iostream>
#include <stdio.h>
#include "MyStruct.h"

using namespace std;
int myAtoi(const char *str);
void main()
{
	int value = myAtoi("-1234");

	cout << "value : " << value << endl;
}

int myAtoi(const char *str)
{
	int result = 0;
	int positionalNumber = 1;

	if (*str == NULL)
		return result;

	bool minusFlag = false;
	if (str[0] == '-')
	{
		minusFlag = true;
		str++;
	}

	while (true)
	{
		char c = *str;
		c -= '0';
		if (c < 0 || 9 < c || c == NULL)
			break;
		result *= positionalNumber;
		result += c;
		if (positionalNumber == 1)
			positionalNumber *= 10;
		str++;
	}

	if (minusFlag)
		result *= -1;

	return result;
}