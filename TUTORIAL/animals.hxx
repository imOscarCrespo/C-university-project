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

#endif