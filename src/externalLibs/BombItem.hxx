#ifndef BombItem_hxx
#define BombItem_hxx

#include "DecoratorItem.hxx"

class BombItem : public DecoratorItem {
	
public:

	BombItem(AbstractItem * absItem) : DecoratorItem(absItem){}


	std::string useItem(Location * location, Character * character);
};

#endif
