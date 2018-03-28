#include "Location.hxx"
#include "Character.hxx"


std::string TrapItem::useItem( Location * newLocation, Character * newCharacter ){
	
	std::string uses = DecoratorItem::useItem( newLocation, newCharacter );

	newLocation->removeItem(getName());
	
	return uses + newCharacter->name() + newCharacter->damage( 5 );
}//useItem
