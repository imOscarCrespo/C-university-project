#ifndef animals_hxx
#define animals_hxx

/*
   - Now we add a new attribute of type std::string
   - Add getters and setters
 */

/*
	void isFriend() const
	{
		std::cout << "is friends with "<< std::endl;
	}

	void amic(std::string Friends){
		_amic = Friends;
	}

	std::string& isFriend(){
		return _amic;
	}
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


	virtual void isFriend() const
	{
		std::cout << "Jumbo, Kermit" << std::endl;
	}
	//Setter
	void amic(std::string theFriend)
	{
		_amic = theFriend;
	}
	//Getter
	std::string& amic()
	{
		return _amic;
	}



private:

	std::string _name;
	std::string _amic;
};






class Elephant : public Animal
{
public:
	void writeSpecies() const
	{
		std::cout << "elephant" << std::endl;
	}

	void isFriend() const
	{
		std::cout << "Pikatxu" << std::endl;
	}
};





class Frog : public Animal
{
public:
	void writeSpecies() const
	{
		std::cout << "frog" << std::endl;
	}

	void isFriend() const
	{
		std::cout << "Pikatxu, Puss in Boots" << std::endl;
	}
};





class Cat : public Animal
{
public:
	void writeSpecies() const
	{
		std::cout << "cat" << std::endl;
	}

	void isFriend() const
	{
		std::cout << "Kermit" << std::endl;
	}
};

#endif/* 
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
        anAnimal.amic("Jumbo y Kermit");
	animals.push_back(&anAnimal);

	Elephant anElephant;
	anElephant.name("Jumbo");
        anElephant.amic("Pikatxu");
	animals.push_back(&anElephant); 

	Frog aFrog;
	aFrog.name("Kermit");
        aFrog.amic("pikatxu");
	animals.push_back(&aFrog);

	Cat aCat;
	aCat.name("Puss in Boots");
        aCat.amic("Pikatxu");
	animals.push_back(&aCat);


	// iterate using iterators
	for (Animals::iterator it=animals.begin(); it!=animals.end(); it++)
	{
            
		std::cout << (*it)->name() << " is of the species ";
                (*it)->writeSpecies();
                std::cout << (*it)->name() << " is friends with ";
                (*it)->isFriend();
	}
        
 
	return 0;
}