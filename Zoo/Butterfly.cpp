#include "Butterfly.h"

Butterfly::Butterfly() {
	this->_type = 5;
	cout << "(Butterfly) Enter the color : ";
	cin >> this->_color;
	cout << "(Butterfly) Butterfly constructed : " << endl;

}
Butterfly::~Butterfly() {
	cout << "(Butterfly) Butterfly destroyed : "<<endl;

}
void Butterfly::print()const {
	Insect::print();
	cout << "(Butterfly) Butterfly color : " <<this->_color <<endl;
	
}
void Butterfly::makeNoise()const {
	cout << "(Horse) Horse noise...ZzZ..." << endl;
}