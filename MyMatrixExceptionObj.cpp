#include "ExceptionObj.h"
void ExceptionObj::printError() const {
	cout << "###################################################" << endl;
	cout << "Error number : " << this->_errorNumber << endl;
	cout << "Error description : " << this->_errorDescription << endl;
	cout << "###################################################" << endl;
}
