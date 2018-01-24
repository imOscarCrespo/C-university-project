#ifndef animals_hxx
#define animals_hxx

/*
   - Now we add a new attribute of type std::string
   - Add getters and setters
 */

#include <iostream>
#include <string>

class Animal
{
public:
	virtual void writeSpecies() const
	{
		std::cout << "...undefined..." << std::endl;
	}
	void name(std::string theName)
	{
		_name = theName;
	}
	std::string& name()
	{
		return _name;
	}

private:
	std::string _name;
};

class Elephant : public Animal
{
public:
	void writeSpecies() const
	{
		std::cout << "elephant" << std::endl;
	}
};

class Frog : public Animal
{
public:
	void writeSpecies() const
	{
		std::cout << "frog" << std::endl;
	}
};

class Cat : public Animal
{
public:
	void writeSpecies() const
	{
		std::cout << "cat" << std::endl;
	}
};

#endif


/* 
   - Use the getters and setters of the attribute _name

   In summary we have learned:
   - how to write to the screen using <iostream>
   - library symbols in the namespace std::
   - classes end in ;
   - methods and attributes are private by default
   - how to define subclasses: "Sub : public Super"
   - the purpose of virtual methods
   - polymorphism
   - use #ifndef in the headers to avoid redefinitions
   - parameter passing by references
   - standard collections vector and list
   - typdefs
   - iterators
   - std::string
   - getters and setters
 */

#include <list>
#include "animals.hxx"

typedef std::list<Animal*> Animals;

int main(void)
{
	Animals animals;

	// introduce one of each type
	Animal anAnimal;
	anAnimal.name("Pikatxu");
	animals.push_back(&anAnimal);

	Elephant anElephant;
	anElephant.name("Jumbo");
	animals.push_back(&anElephant); 

	Frog aFrog;
	aFrog.name("Kermit");
	animals.push_back(&aFrog);

	Cat aCat;
	aCat.name("Puss in Boots");
	animals.push_back(&aCat);


	// iterate using iterators
	for (Animals::iterator it=animals.begin(); it!=animals.end(); it++)
	{
		std::cout << (*it)->name() << " is of the species ";
		(*it)->writeSpecies();
	}

	return 0;
}