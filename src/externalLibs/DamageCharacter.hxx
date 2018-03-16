#ifndef DAMAGECHARACTER_HXX
#define DAMAGECHARACTER_HXX

#include <MiniCppUnit.hxx>
#include "Exception.hxx"
#include "Character.hxx"

class DamageCharacter : public Character
{

public:
	DamageCharacter(){}
	~DamageCharacter(){}

	std::string receiveMagic (int magicPoint){
		std::string output = "";

		output = this->name() + " receives " + std::to_string(magicPoint) + " magic points\n" +
		this->name() + " takes " + std::to_string(magicPoint) + " damage\n";

		return output;
	}

};


#endif //DamageCharacter_hxx
