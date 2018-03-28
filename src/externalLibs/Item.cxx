#include "Location.hxx"
#include "Character.hxx"

std::string Item::useItem ( Location * newLocation, Character * newCharacter )
{
	return newCharacter->name() + " uses " + this->_name + " at " + newLocation->name() + "\n";
}
