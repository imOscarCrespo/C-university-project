#include "AbstractItem.hxx"

class Iterator : public AbstracItem
{
	
	AbstractItem *_decorator;
	public:
		
		ItemDecorator(AbstractItem *decorator) : _decorator(decorator){}

		virtual ~ItemDecorator(){}
		virtual string useItem(Character *anonymous) = 0;

};