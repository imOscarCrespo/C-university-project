#include "Location.hxx"
#include "Character.hxx"


std::string PotionItem::useItem( Location * newLocation, Character * newCharacter ){
	
	std::string uses = DecoratorItem::useItem( newLocation, newCharacter );

	newLocation->removeItem(getName()); 
	
	return uses + newCharacter->name() + newCharacter->cure( 5 );
} 
