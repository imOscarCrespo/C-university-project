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