/// Course:  CS213 - Programming II  - 2018
/// Title:   Assignment 2 - Task 3
/// Program: CS213-2018-A1-T3
/// Author:  Dr. Mohammad El-Ramly
/// Date:    10 August 2018
/* programmers: Ahmed Sayed Mansour   20170022
				Eslam Saleh Mohamed   20170046
				Eslam Mohamed Mahmoud 20170049
*/
/// last edit : 26/10/2018
/// Version: 1.0

#include "BigDecimalInt.h"

//A function to fill all elements of the another smaller string with zeros
void BigDecimalInt::fillZeros(int maxSize, string& str1, string& str2)
{
	int diff;

	if (str1.length() > str2.length())
	{
		diff = maxSize - str2.length();
		for (int i = 0; i < diff; i++)
			str2 = "0" + str2;
	}
	else if (str1.length() < str2.length())
	{
		diff = maxSize - str1.length();
		for (int i = 0; i < diff; i++)
			str1 = "0" + str1;
	}
}

//Constractor of adding a string value
BigDecimalInt::BigDecimalInt(string num)
{
	str = num;
}

//Constractor of adding an integer value and converting to a string
BigDecimalInt::BigDecimalInt(int num = 0)
{
	stringstream convert;
	convert << num;
	str = convert.str();
}

//Operator + to get the sum of numbers
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt other)
{
	string first = str;
	string second = other.str;

	bool bothNegative = false;
	if (first[0] == '-' && second[0] == '-') //if both are negative, then add and append -ve sign to the result
	{
		bothNegative = true;
		first = first.substr(1);
		second = second.substr(1);
	}
	else if (first[0] == '-')
	{
		BigDecimalInt negative(first.substr(1)); // removing the -ve sign;
		return other - negative;
	}
	else if (second[0] == '-')
	{
		BigDecimalInt negative(second.substr(1)); // removing the -ve sign;
		BigDecimalInt thisStr(first);
		return thisStr - negative;
	}
	int maxSize = (first.length() > second.length()) ? first.length() : second.length();
	fillZeros(maxSize, first, second);
	string result = "";
	int temp;
	bool carry = false;
	for (int i = maxSize - 1; i >= 0; i--)
	{
		temp = (first[i] + second[i] - 48);
		if (carry)
			temp = (first[i] + second[i] - 48) + 1;
		if ((temp - 48) > 9)
		{
			temp -= 10;
			carry = 1;
		}
		else
			carry = 0;

		result = (char)(temp)+result;
	}
	if (carry)
		result = "1" + result;

	if (bothNegative)
		result = "-" + result;

	BigDecimalInt sum(result);
	return sum;
}

//Operator - to get the value of number - another number
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt other)
{
	string first = str;
	string second = other.str;
	if (first[0] == '-' && second[0] == '-')
		//if both are negative, then other becomes +ve ; -123- (-200) = -123 + 200 = 200-123
	{
		first = first.substr(1);
		second = second.substr(1);

		// swap the two numbers
		string temp = first;
		first = second;
		second = temp;
	}
	else if (first[0] == '-')
	{
		//(if the first is negative, then call + and add -ve sign to the result (-123 - 200) = -(123+200)

		first = first.substr(1);
		BigDecimalInt temp(first);
		BigDecimalInt sum = temp + other;

		sum.str = "-" + sum.str;
		return sum;
	}
	else if (second[0] == '-')
	{
		//(if the second is negative, then call Add (100 - (-100) = 100+100)
		BigDecimalInt negative(second.substr(1)); // removing the -ve sign;
		BigDecimalInt thisStr(first);

		return thisStr + negative;
	}
	int maxSize = (first.length() > second.length()) ? first.length() : second.length();
	fillZeros(maxSize, first, second);

	bool secondIsGreater = false;
	if (second[0] > first[0])
	{
		// swap the two numbers and add -ve sign to the result
		string temp = first;
		first = second;
		second = temp;

		secondIsGreater = true;
	}
	string result = "";
	int temp;
	bool borrow = false;

	for (int i = maxSize - 1; i >= 0; i--)
	{
		temp = first[i];

		if (borrow)
		{
			temp = first[i] - 1;
			borrow = false;
		}
		if (temp >= second[i])
		{
			result = (char)(temp - second[i] + 48) + result;
			borrow = false;
		}
		else if (temp < second[i])  // borrow
		{
			temp += 10;
			borrow = true;
			result = (char)(temp - second[i] + 48) + result;
		}
	}
	if (secondIsGreater)
		result = "-" + result;

	BigDecimalInt sub(result);
	return sub;
}

//A friend Ostream function to print out the requeted value
ostream& operator << (ostream& out, BigDecimalInt printStr)
{
	out << printStr.str;
	return out;
}

