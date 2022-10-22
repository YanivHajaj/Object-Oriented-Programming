#include "Animal.h"
Animal::Animal() {
	this->_type = 0;
		cout << "(Animal) Enter the name : ";
		cin >> this->_name;
	cout <<"(Animal) Enter the age : ";
	cin >> this->_animalAge;
	cout << "(Animal) Animal created"<<endl;
}
Animal::~Animal() {
	cout << "(Animal) Animal destroyed"<<endl;
}
void Animal::print()const {
	cout << "(Animal) Name : " << this->_name << endl;
	cout << "(Animal) Age : " << this->_animalAge<< endl;
}
void Animal::makeNoise()const {
	cout << "(Animal) Animal noise...ZzZ..." << endl;
}
