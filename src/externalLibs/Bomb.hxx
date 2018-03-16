#include <MiniCppUnit.hxx>
#include "Character.hxx"
#include "ItemDecorator.hxx"
#include <string>
#include <iostream>

class Bomb : public ItemDecorator
{
	public:
		Bomb(AbstractItem *decorator):ItemDecorator(decorator){}
		~Bomb(){}
		/*std::string useItem(Character *anonymous)
		{
				return "Bomb explodes\n";
		}*/
};