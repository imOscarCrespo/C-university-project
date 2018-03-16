
#include <MiniCppUnit.hxx>
#include "Character.hxx"
#include "ItemDecorator.hxx"
#include <string>
#include <iostream>

class Trap : public ItemDecorator
{
	public:
		Trap(AbstractItem *decorator):ItemDecorator(decorator){}
		~Trap(){}
		/*std::string useItem(Character *anonymous)
		{
			return anonymous->name() + " takes 5 damage\n";
		}*/
};