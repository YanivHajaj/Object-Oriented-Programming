#pragma once
#include<iostream>
#include<string>
using namespace std;
#define EXP0 "Regular error"
#define EXP1 "matrix range cannot be less than 0"
#define EXP2 "Cannot divide zero by zero"
#define EXP3 "Buffer overflow"
#define EXP4 "Buffer underflow"
#define EXP5 "Pointer is NULL"
#define EXP6 "cannot add or subtruct two matrices with range diffrence (columns/rows)"
#define EXP7  "multiply error : first matrix columns doesnt match second matrix rows"
#define EXP8 "cannot use = operator. Matrices with different number of rows or columns"

class ExceptionObj
{
private:
	string _errorDescription;
	int _errorNumber;
public:
	ExceptionObj(int en = 0, string d = EXP0) :_errorDescription(d), _errorNumber(en) {}
	void printError()const;
};

