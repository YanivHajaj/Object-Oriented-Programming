#include "Mammel.h"


Mammel::Mammel() {
	this->_type = 1;
	cout << "(Mammel) Got milk (T/F)? ";
	char ch;
	cin >> ch;
	if (ch == 'T' || ch == 't')
		this->_gotMilk = true;
	else
		this->_gotMilk = false;
	cout << "(Mammel) Mammel constructed " << endl;
}
Mammel::~Mammel() {
	cout << "(Mammel) Mammel destroyed" << endl;
}
void Mammel::print()const {
	Animal::print();
	if (this->_gotMilk)
		cout << "(Mammel) got milk"<<endl;
	else
		cout << "(Mammel) didn't get milk"<<endl;
}
void Mammel::makeNoise()const {
	cout << "(Mammel) Mammel noise...ZzZ..." << endl;
}