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

#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

class BigDecimalInt
{
private:
	string str;
	void fillZeros(int maxSize, string& str1, string& str2);  //A function to fill all elements of the another smaller string with zeros
public:

	//Constractor of adding a string value
	BigDecimalInt(string num);

	//Constractor of adding an integer value
	BigDecimalInt(int num);

	//Operator + to get the sum of numbers
	BigDecimalInt operator+ (BigDecimalInt other);

	//Operator - to get the value of number - another number
	BigDecimalInt operator- (BigDecimalInt other);

	//A friend Ostream function to print out the requeted value
	friend ostream& operator << (ostream& out, BigDecimalInt printStr);

};

#endif // BIGDECIMALINT_H
