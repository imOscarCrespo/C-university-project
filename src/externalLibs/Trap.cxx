#ifndef TrapItem_hxx
#define TrapItem_hxx

#include "DecoratorItem.hxx"

class TrapItem : public DecoratorItem {
	
public:

	TrapItem(AbstractItem * absItem) : DecoratorItem(absItem){}
	
	std::string useItem(Location * loc, Character * character){
		std::string uses = DecoratorItem::useItem( loc, character );

		return uses + character->name() + character->damage( 5 );
	}//useItem
	
};

#endif
