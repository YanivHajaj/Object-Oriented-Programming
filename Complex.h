#pragma once
/*
 * This class represents a complex number with real and imagenary variables.
 * you can create, add, subtruct and print numbers(include thier distance from the origin and phase).
 */

class Complex
{
private:
	int _re;
	int _im;
public:
	// --------------  Getters  ---------------
	int getRe() const{ return _re; }
	int getIm() const{ return _im; }
	// --------------  Getters  ---------------

	// ------------  Constructors  ------------
	Complex(Complex& other); //copy constructor get a complex number and create a copy.
	Complex(int re, int im); //constructor for full complex number, get imegenary and real values.
	Complex(); //default constructor initialize imegenary=0 and real=0.
	// ------------  Constructors  ------------

	// --------------  Setters  ---------------
	void setRe(int re);//set real
	void setIm(int im);//set imegenary
	void setComplexNum(int re, int im);//set full complex number, get imegenary and real values.
	// --------------  Setters  ---------------

	// ---------  Arithmetic methods  ---------
	double absoluteValue() const; //return absolute value of the number (double)
	double phase()const;//return the argument of the number (in radians)
	Complex add(const Complex& other)const; //return new number, the number is the sum of the two numbers. 
	Complex sub(const Complex& other)const; ////return new number, the number is the subtraction of the two numbers.
	void print()const;//print num by the shape:𝑥 + 𝑦i (r, θ)
	// ---------  Arithmetic methods  ---------
};

