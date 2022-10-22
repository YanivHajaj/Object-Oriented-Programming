#include "Zoo.h"

Zoo::~Zoo() //desractor
{
	for (int i = 0; i < this->_numOfAnimals; i++)
		delete this->_allAnimals[i];
	delete this->_allAnimals;
}

void Zoo::printAllAnimals() const
{
	cout << "Zoo name : " << this->_zooName << endl;
	if(this->_numOfAnimals==0){
		cout << "Empthy Zoo : " << endl;
		return;
	}
	cout << "number of animals : " << this->_numOfAnimals<< endl;
	for (int i = 0; i < this->_numOfAnimals; i++) {
		cout << "*******************************" << endl;
		this->_allAnimals[i]->print();
		cout << "*******************************" << endl;
	}


}
void Zoo::animalsParty() const
{
	cout << "Zoo name : " << this->_zooName << endl;
	if (this->_numOfAnimals == 0) {
		cout << "Empthy Zoo : " << endl;
		return;
	}
	cout << "number of animals : " << this->_numOfAnimals << endl;
	for (int i = 0; i < this->_numOfAnimals; i++) {
		cout << "*******************************" << endl;
		this->_allAnimals[i]->makeNoise();
		cout << "*******************************" << endl;
	}
}
void Zoo::insertAnAnimal()
{
	Animal** temp = new Animal * [this->_numOfAnimals + 1];
	for (int i = 0; i < this->_numOfAnimals; i++)
		temp[i] = _allAnimals[i];
	delete[] this->_allAnimals;
	this->_allAnimals = temp;
	this->_numOfAnimals++;
	cout << "Sub menu" << endl;
	cout << "*****************" << endl;
	cout << "0) regular animal" << endl;
	cout << "1) Mammel " << endl;
	cout << "2) Insect " << endl;
	cout << "3) Lion" << endl;
	cout << "4) Horse" << endl;
	cout << "5) Butterfly" << endl;
	cout << "Your chice : " << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 0:
		this->_allAnimals[_numOfAnimals - 1] = new Animal;
		break;
	case 1:
		this->_allAnimals[_numOfAnimals - 1] = new Mammel;
		break;
	case 2:
		this->_allAnimals[_numOfAnimals - 1] = new Insect;
		break;
	case 3:
		this->_allAnimals[_numOfAnimals - 1] = new Lion;
		break;
	case 4:
		this->_allAnimals[_numOfAnimals - 1] = new Horse;
		break;
	case 5:
		this->_allAnimals[_numOfAnimals - 1] = new Butterfly;
		break;
	default:
		this->_allAnimals[_numOfAnimals - 1] = new Animal;
		break;
	}
	cout << "Animal added..." << endl;
}
int Zoo::findAnimalByName() const
{
	cout << "Enter the name of the animal: " <<endl;
	string str;
	cin >> str;
	for (int i = 0; i < this->_numOfAnimals; i++)
		if (this->_allAnimals[i]->getName() == str)
			return i;
	return -1;//animal doesn't exist
}
void Zoo::removeAnimalByName()
{
	int index = this->findAnimalByName();
	if (index == -1) {
		cout << "No such Animal..." << endl;
		return;
	}
	delete this->_allAnimals[index];
	this->_allAnimals[index]=NULL; 
	this->_allAnimals[index] = this->_allAnimals[this->_numOfAnimals - 1];
	Animal** temp = new Animal * [this->_numOfAnimals - 1];
	for (int i = 0; i < this->_numOfAnimals - 1; i++)
		temp[i] = this->_allAnimals[i];
	delete[] this->_allAnimals;
	this->_allAnimals = temp;
	this->_numOfAnimals--;
	cout << "Animal removed..." << endl;
}
void Zoo::menu()
{
	int choice,index;
	while (true) {
		cout << "Menu" << endl;
		cout << "****" << endl;
		cout << "0) EXIT " << endl;
		cout << "1) print all animals " << endl;
		cout << "2) Insert a new animal " << endl;
		cout << "3) Animals party " << endl;
		cout << "4) remove animal by name " << endl;
		cout << "5) find an animal by name" << endl;
		cout << "Your choice :  " << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "C u again, salamat..." << endl;
			return;
		case 1:
			this->printAllAnimals();
			break;
		case 2:
			this->insertAnAnimal();
			break;
		case 3:
			this->animalsParty();
			break;
		case 4:
			this->removeAnimalByName();
			break;
		case 5:
			index = this->findAnimalByName();
			if (index == -1)
				cout << "no such animal..." << endl;
			else {
			    cout << "Found at index : " <<index<< endl;
				this->_allAnimals[index]->print();
			}
			break;
		default:
			cout << "Wrong choice, please try again..." << endl;
		}
	}
}

void Zoo::sortAllAnimalsByName()
{
}
void Zoo::sortAllAnimalsByAge() {

}
void Zoo::sortAllAnimalsByType() {

}
//void printNumberOfPureMammels()const;
void Zoo::printNumberOfAnyType()//typeid
{

}
void Zoo::printNumberOfMammels()const//dynamic cast
{

}