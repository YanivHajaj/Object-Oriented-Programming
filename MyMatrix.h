#pragma once
#include <iostream>
using namespace std;

class MyMatrix
{
private:
	double** _matrix;
	int _n;
	int _m;
public:
	int getM() const { return _m; }
	int getN() const { return _n; }
	//get value+number of row and column. set the value inside the matrix.
	void setValue(int row, int column, double value) const { this->_matrix[row][column] = value; };
	double getValueByIndex(int row, int column)const { return this->_matrix[row][column]; };
	MyMatrix(const MyMatrix& other);//copy constructor
	MyMatrix(int m, int n);//constuctor getting m=rows,n=columns (set all to martix to 0)
	MyMatrix();//default constructor, use the constructor getting two numbers(3,3)
	void printMatrix()const;//print the matrix
	~MyMatrix();//destructor

	//---------------binary operators------------------//
	MyMatrix operator+(const MyMatrix& other)const;//add two matrecis,return MyMatrix type
	MyMatrix operator-(const MyMatrix& other)const;//sub two matrecis,return MyMatrix type
	MyMatrix operator*(MyMatrix& other); //multiply two matrecis return MyMatrix type
	MyMatrix operator*(int num); //multiply matrix with number return MyMatrix type
	MyMatrix& operator=(const MyMatrix& other);//put one marix into another,return MyMatrix type.
	//---------------binary operators------------------//

	//---------------binary friend operators-----------//
	friend istream& operator>>(istream& in, MyMatrix& other);//get values from user and update the matrix,return istream type
	friend ostream& operator<<(ostream& out, MyMatrix& other);//print matrix,return ostream type
	friend MyMatrix operator*(int num, MyMatrix& other); //friend multiply *
	//---------------binary friend operators-----------//
	// 
	//---------------compartion operator---------------//
	bool operator==(const MyMatrix& other);
	//---------------compartion operator---------------//

	//---------------onary operators-------------------//
	double* operator[](int index);
	operator double() const; //casting operator return sum of matrix
	//---------------onary operators-------------------//
};

