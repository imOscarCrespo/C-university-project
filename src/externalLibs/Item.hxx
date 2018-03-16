/*
*	PRACTICA 3 : Xavier Maltas i Oscar Crespo
*/
//#include <Exception.hxx>

#ifndef ITEM_HXX
#define ITEM_HXX 

#include <MiniCppUnit.hxx>
#include "Character.hxx"
#include "AbstractItem.hxx"


#include <iostream>
#include <string>
// #include "Exception.hxx"

class Item : public AbstractItem 
{

	public:
		Item(){}
		~Item(){}
		std::string useItem(Character *anonymous){return "";}

};



#endif
