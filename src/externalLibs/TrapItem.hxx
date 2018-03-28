#ifndef TrapItem_hxx
#define TrapItem_hxx

#include "DecoratorItem.hxx"

class TrapItem : public DecoratorItem {
	
public:

	TrapItem(AbstractItem * absItem) : DecoratorItem(absItem){}
	
	std::string useItem(Location * location, Character * character);
	
};

#endif
