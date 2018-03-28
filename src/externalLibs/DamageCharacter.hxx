#ifndef DamageCharacter_hxx
#define DamageCharacter_hxx

#include "Character.hxx"

class DamageCharacter : public Character {

public:

	DamageCharacter ( const std::string name, const unsigned level ) {
		_name = name;
		_level = level;
	}//DamageCharacter

	std::string receiveMagic(const unsigned points){
		std::stringstream devolver;
		damage(points);
		devolver << Character::receiveMagic(points) << name() << " takes " << points <<" damage\n";
		return devolver.str();	
	}//receiveMagic
};

#endif
