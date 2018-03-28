#ifndef PotionItem_hxx
#define PotionItem_hxx

#include "DecoratorItem.hxx"

class PotionItem : public DecoratorItem {
	
public:

	PotionItem(AbstractItem * absItem) : DecoratorItem(absItem){}
	
	std::string useItem(Location * location, Character * character);
	
};

#endif
