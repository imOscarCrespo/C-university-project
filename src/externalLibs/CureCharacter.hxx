#ifndef CureCharacter_hxx
#define CureCharacter_hxx

#include "Character.hxx"

class CureCharacter : public Character {

public:

	CureCharacter ( const std::string name, const unsigned int level ){
		_name = name;
		_level = level;
	}//CureCharacter

	std::string receiveMagic(const unsigned int points){
		std::stringstream devolver;
		cure(points);
		devolver << Character::receiveMagic(points) << name() << " gains " << points <<" life\n"; 
		return devolver.str();	
	}//reciveMagic
};

#endif
