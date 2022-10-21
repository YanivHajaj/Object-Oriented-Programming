#include "MyMatrix.h"
#include "ExceptionObj.h"

MyMatrix::MyMatrix(const MyMatrix& other)
{
	this->_m = other.getM();
	this->_n = other.getN();
	this->_matrix = new double* [this->getM()];
	for (int i = 0; i < other._m; i++)
	{
		this->_matrix[i] = new double[this->getN()];
	}
	for (int i = 0; i < other._m; i++)
		for (int j = 0; j < other._n; j++)
			this->setValue(i, j, other.getValueByIndex(i,j));
	
}
void MyMatrix::printMatrix()const {
	cout << "***************" << endl;
	for (int i = 0; i < this->getM(); i++)
	{
		for (int j = 0; j < this->getN(); j++)
			cout << "[" << this->_matrix[i][j] << "]";
		cout << endl;
	}
	cout << "***************" << endl;
}
MyMatrix::MyMatrix(int m, int n) {
	/*if(m<0||n<0)
		throw*/
	this->_m = m;
	this->_n = n;
	double** newMatrix = new double* [m];
	for (int i = 0; i < m; i++)
		newMatrix[i] = new double[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			newMatrix[i][j] = 0;
	this->_matrix = newMatrix;
}
MyMatrix::MyMatrix() {
	this->_m = 3;
	this->_n = 3;
	double** newMatrix = new double* [3];
	for (int i = 0; i < 3; i++)
		newMatrix[i] = new double[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			newMatrix[i][j] = 0.0;
	this->_matrix = newMatrix;
}
MyMatrix::~MyMatrix() {
	for (int i = 0; i < this->getM(); i++)
		delete this->_matrix[i];
	delete[] this->_matrix;

}
MyMatrix MyMatrix::operator+(const MyMatrix& other)const
{
	int i = 0, j = 0;
	if (this->getM() != other.getM() || this->getN() != other.getN()) {
		throw ExceptionObj(6, EXP6);//EXP6 "cannot add\subtruct two matrices with range diffrence (columns/rows)"
	}
	MyMatrix Matrix_after_plus(this->getM(), this->getN());
	for (i = 0; i < this->getM(); i++)
	{
		for (j = 0; j < this->getN(); j++)
			Matrix_after_plus.setValue(i, j, this->getValueByIndex(i, j) + other.getValueByIndex(i, j));
	}
	return Matrix_after_plus;
}
MyMatrix MyMatrix::operator-(const MyMatrix& other)const
{
	int i = 0, j = 0;
	MyMatrix Matrix_after_sub(this->getM(), this->getN());
	if (this->getM() != other.getM() || this->getN() != other.getN()) {
		throw ExceptionObj(6, EXP6); //EXP6 "cannot add\subtruct two matrices with range diffrence (columns/rows)"
	}
	for (i = 0; i < this->getM(); i++)
	{
		for (j = 0; j < this->getN(); j++)
		{
			Matrix_after_sub._matrix[i][j] = this->_matrix[i][j] - other._matrix[i][j];
		}
	}
	return Matrix_after_sub;
}
MyMatrix MyMatrix::operator*(MyMatrix& other)
{
	if (this->getN() != other.getM())
		throw ExceptionObj(7, EXP7); //EXP7  "first matrix columns doesnt match second matrix rows" 
		//Multiply the elements of A and B
	int i = 0, j = 0, k = 0;
	double sum = 0;
	MyMatrix matrixAfterMul(this->getM(), other.getN());
	//Check order of Matrix this and other
	for (i = 0; i < this->getM(); i++) {
		for (j = 0; j < other.getN(); j++) {
			sum = 0;
			for (k = 0; k < other.getM(); k++) {
				sum += (this->_matrix[i][k] * other._matrix[k][j]);
			}
			matrixAfterMul._matrix[i][j] = sum;
		}
	}
	return matrixAfterMul;
}
MyMatrix operator*(int num, MyMatrix& other) {
	MyMatrix MatrixAfterMul;
	for (int i = 0; i < other.getM(); i++)
	{
		for (int j = 0; j < other.getN(); j++)
		{
			MatrixAfterMul[i][j] = other[i][j] * num;
		}
	}
	return MatrixAfterMul;
}
MyMatrix& MyMatrix::operator=(const MyMatrix& other) {
	if (this->getM() != other.getM() || this->getN() != other.getN()) 
		throw ExceptionObj(8, EXP8);//EXP8 cannot use = operator. Matrices with different number of rows or columns.
		for (int i = 0; i < this->getM(); i++)
			delete this->_matrix[i];
		delete[] this->_matrix;
		this->_m = other.getM();
		this->_n = other.getN();
		this->_matrix = new double* [this->getM()];
		for (int i = 0; i < other._m; i++)
		{
			this->_matrix[i] = new double[this->getN()];
		}
		for (int i = 0; i < other._m; i++)
			for (int j = 0; j < other._n; j++)
				this->_matrix[i][j] = other._matrix[i][j];
		return *this;

}
istream& operator>>(istream& in, MyMatrix& other)
{
	double userValue;
	for (int i = 0; i < other.getM(); i++)
	{
		cout << "Insert values for row number : " << i + 1 << endl;
		for (int j = 0; j < other.getN(); j++)
		{
			in >> userValue;
			other.setValue(i, j, userValue);
		}
	}
	return in;
}
MyMatrix MyMatrix::operator*(int num)
{
	MyMatrix matrixAfter_numMUlMatrix;
	for (int i = 0; i < this->getM(); i++)
	{
		for (int j = 0; j < this->getN(); j++)
		{
			matrixAfter_numMUlMatrix._matrix[i][j] = this->_matrix[i][j] * num;
		}
	}
	return matrixAfter_numMUlMatrix;
}
ostream& operator<<(ostream& out, MyMatrix& other)
{
	other.printMatrix();
	return out;
}
bool MyMatrix::operator==(const MyMatrix& other) {
	for (int i = 0; i < this->getM(); i++)
		for (int j = 0; j < this->getN(); j++)
			if (this->_matrix[i][j] != other._matrix[i][j])
				return false;
	return true;
}
double* MyMatrix::operator[](int index) {
	if (index > this->getM())
		throw ExceptionObj(3, EXP3);
	if (index < 0)
		throw ExceptionObj(4, EXP4);

	return this->_matrix[index];
}
MyMatrix::operator double() const
{
	double sum = 0;
	for (int i = 0; i < this->getM(); i++)
	{
		for (int j = 0; j < this->getN(); j++)
			sum += this->_matrix[i][j];
	}
	return sum;
}
