#include "Complex.h"
// Used to calculate the absolute value and the phase
#include "Math.h"
// Used for the print function
#include "iostream"
using namespace std;

//**explnation about each method in header file.
// --------------  Setters  ---------------
void Complex::setRe(int re) {
	_re = re;
}
void Complex::setIm(int im) {
	_im = im;
}
void Complex::setComplexNum(int re, int im) {
	setRe(re);
	setIm(im);
}
// --------------  Setters  ---------------

// ------------  Constructors  ------------
Complex::Complex(Complex& other) {
	this->setComplexNum(other.getRe(), other.getIm());
}
Complex::Complex(int re, int im) {
	this->setRe(re);
	this->setIm(im);
}
Complex::Complex() {
	setRe(0);
	setIm(0);
}
// ------------  Constructors  ------------

// ---------  Arithmetic methods  ---------
// distance from origin = Sqrt(Real(X)^2 + Imag(X)^2)
double Complex::absoluteValue()const {
	return (sqrt(pow(this->getRe(), 2) + pow(this->getIm(), 2)));
}
//  Phase = atan2(Imag(X), Real(X))
double Complex::phase()const {
	return atan2((this->getIm()) , (this->getRe()));
}
Complex Complex::add(const Complex& other)const {
	Complex NewNum;
	NewNum.setComplexNum(this->getRe() + other.getRe(), this->getIm() + other.getIm());
	return NewNum;
}
Complex Complex::sub(const Complex& other)const {
	Complex NewNum;
	NewNum.setComplexNum(this->getRe() - other.getRe(), this->getIm() - other.getIm());
	return NewNum;
}
void Complex::print()const {
	if (this->getRe() == 0 && this->getIm() == 0) //both 0
		cout << "0 (0,0)" << endl;
	if (this->getRe() == 0 && this->getIm() != 0) //re =0 , im != 0
		cout <<this->getIm() << "i (" << this->absoluteValue() << "," <<this->phase() <<")" << endl;
	if (this->getRe() != 0 && this->getIm() == 0) //re !=0, im = 0 
		cout << this->getRe() << " (" << this->absoluteValue() << "," << this->phase() << ")" << endl;
	if (this->getRe() != 0&&this->getIm() > 0) //im > 0 
		cout << this->getRe() << " + " << this->getIm() << "i (" << this->absoluteValue() << "," << this->phase() << ")" << endl;
	if(this->getRe() != 0&&this->getIm() < 0) //im < 0
		cout << this->getRe() << " - " << (this->getIm()*-1) << "i (" << this->absoluteValue() << "," << this->phase() << ")" << endl;

}
// ---------  Arithmetic methods  ---------
