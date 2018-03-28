#include "Location.hxx"
#include "Character.hxx"


std::string BombItem::useItem( Location * newLocation, Character * newCharacter ){
	
	std::string uses = DecoratorItem::useItem( newLocation, newCharacter );
	if(this->hasMagic() == true){ 
		newLocation->removeItem(getName()); 
		uses += "Bomb explodes\n";
		uses += newLocation->distributeMagic( 5 );
		return uses; 
	}
	else{
		return "Bomb not enabled\n"; 
	}
	
}

