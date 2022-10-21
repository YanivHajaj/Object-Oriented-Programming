#include<iostream>
#include"Complex.h"
using namespace std;
void main(){
	Complex zero;//default constructor
	cout << "zero = "; zero.print();
	//constructors getting two numbers(positive, negative, etc..)
	Complex positive(4,5);
	cout << "Positive = "; positive.print();
	Complex negative(-4, -5);
	cout << "negative = "; negative.print();
	Complex zeroPositive(0, 4);
	cout << "zeroPositive = "; zeroPositive.print();
	Complex negativeZero(-8, 0);
	cout << "negativeZero = "; negativeZero.print();
	Complex zeroNegative(0, -3);
	cout << "zeroNegative = "; zeroNegative.print();
	Complex copy(negative);//copy constructor 
	cout << "copy = "; copy.print();
	cout << "******************" << endl;
	cout << "negative + positive = "; negative.add(positive).print();
	cout << "zreo + positive = "; zero.add(positive).print();
	cout << "negativeZero - positive = "; negativeZero.sub(positive).print();
	cout << "setting copy number to -3 + 3i" << endl;
	copy.setComplexNum(-3, 3);
	cout << "Real part of new copy is: = " << copy.getRe() << endl;
	cout << "imegenary part of new copy is: = " << copy.getIm() << endl;
}
