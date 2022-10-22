#include "Lion.h"
Lion::Lion() {
	this->_type = 3;
	cout << "(Lion) Enter the volume : ";
	cin>>this->_volume;
	cout << "(Lion) Lion constructed " << endl;
}
Lion::~Lion(){
	cout << "(Lion) Lion destroyed" << endl;
	}
void Lion::print() const {
	Mammel::print();
	cout << "(Lion) volume : " << this->_volume << endl;
}
void Lion::makeNoise() const {
	cout << "(Lion) Lion noise...ZzZ..." << endl;
}