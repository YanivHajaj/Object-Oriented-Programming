#include"MyMatrix.h"
#include"ExceptionObj.h"
#include <iostream>
using namespace std;
int main() {
	{
		MyMatrix mDefault;//default constructor
		MyMatrix matrix3X5(3, 5), matrix2X2(2, 2), matrix2X4(2, 4), matrix4X2(4, 2);//constructor getting rows and coloumns
		 //set all values of matrix3X5 to 2
		for (int i = 0; i < mDefault.getM(); i++)
			for (int j = 0; j < mDefault.getN(); j++)
				mDefault.setValue(i, j, 2);
		MyMatrix mCopy(mDefault),matrix3X3(mDefault);//copy constructor
		 //set all values of matrix3X3 to 3
		for (int i = 0; i < matrix3X3.getM(); i++)
			for (int j = 0; j < matrix3X3.getN(); j++)
				matrix3X3.setValue(i, j, 3);
		try {
			matrix3X3 = matrix3X3 + matrix3X3 + (matrix3X3 - matrix3X3) - matrix3X3;//add and subtruct with the same numbers of rows and columns
			cout << matrix3X3 << endl;//print matrix
			matrix3X3 = matrix3X5 + mDefault ;//EXP6 matrix3X5(3,5) cannot add with mDefault(3,3). exeption throw
		}
		catch (ExceptionObj e)
		{
			e.printError();
		}
		
		try {
			matrix3X3 = 2*matrix3X3 *2 ;//multiplt using Mymatrix-int * friend *
			cout << matrix3X3 << endl;//print matrix
			matrix3X3 =  matrix3X3* matrix3X5;//EXP8 "cannot use = operator. Matrices with different number of rows or columns.  "
		    }
		catch (ExceptionObj e)
		{
			e.printError();
		}
		try {
			matrix3X3 = matrix3X3 * matrix3X3 * matrix3X3;//operator * for My Mymatrix objects
			cout << "matrix3X3 :" <<endl<< matrix3X3 <<  endl;//print matrix
			matrix3X3 = (matrix3X5 * matrix3X3) * mDefault;//EXP7 (matrix3X5 * matrix3X3) range is (5,3) cannot multiply with mDefault(3,3). exeption throw
		}
		catch (ExceptionObj e)
		{
			e.printError();
		}
		try {
			cin >> matrix2X2; //create matrix using user values
			cout << "matrix2X2 : " << endl << matrix2X2 << endl;//print matrix
		}
		catch (ExceptionObj e)
		{
			e.printError();
		}
		int row, column;
		cout << "enter row and column index in order to get value from matrix using [][] operator "<<endl;
		cin >> row >> column;
		if (column >= 0 && column < matrix2X2.getN()) //columns in range
		{
			try {
				cout << "use operator [][] on MyMatrix type : " <<  endl;
				cout << "matrix2X2 in row :" <<row<<"and column : " <<column << " is : " << matrix2X2[row][column] << endl;
			}
			catch (ExceptionObj e) //rows out of range
			{
				e.printError();
			}
		}
		else
			if(row<0||row>matrix2X2.getM())
				cout << "both rows and columns are out of range " <<  endl;
			else
				cout << "columns out of range " <<  endl;
		cout << "casting on Matrix : " << (double) matrix2X2 << endl;//casting
		if (matrix2X2 == matrix2X2)//comparing two matrices
			cout << "the matrecis are qeuals " << endl;
		return 0;
	}
}
