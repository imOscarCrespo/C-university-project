#include <MiniCppUnit.hxx>
#include "Character.hxx"
#include "ItemDecorator.hxx"
#include <string>
#include <iostream>

class Potion : public ItemDecorator
{
	public:
		Potion(AbstractItem *decorator):ItemDecorator(decorator){}
		~Potion(){}
		/*std::string useItem(Character *c)
		{
			return c->name() + " gains 5 life\n";
		}*/
};