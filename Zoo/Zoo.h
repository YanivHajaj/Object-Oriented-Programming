#pragma once
#include"Horse.h"
#include"Lion.h"
#include"Butterfly.h"
class Zoo
{
private:
	string _zooName;
	int _numOfAnimals;
	Animal** _allAnimals;
public:
	Zoo(string n):_zooName(n),_numOfAnimals(0),_allAnimals(NULL){}
	~Zoo();
	void printAllAnimals() const;
	void animalsParty() const;
	void insertAnAnimal();
	int findAnimalByName() const;
	void removeAnimalByName();
	void menu();
	void sortAllAnimalsByName();
	void sortAllAnimalsByAge();
	void sortAllAnimalsByType();
	//void printNumberOfPureMammels()const;
	void printNumberOfAnyType();//typeid
	void printNumberOfMammels()const;//dynamic cast
};

