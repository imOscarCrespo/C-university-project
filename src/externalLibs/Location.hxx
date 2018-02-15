/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

//Location.hxx

#ifndef LOCATION_HXX
#define LOCATION_HXX
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

#include <Item.hxx>


	
class Location{

//ATRIBUTS d'entrada
std::string _name;
//
typedef std::list<Item*> Items;

public:
	//Llista d'Items
	Items _items;
	//Constructor de la classe

	Location()
		//inicialització per defecte
		: _name("unknown")	
	{

		 
	}


	//Metodes de la classe
		//Getter de name
		const std::string & name() const
		{
			return _name;
		}
		//Setter de name
		void name(const std::string &theName)
		{
			_name = theName;
		}

		//Empty Description
		std::string description() const
		{
			return "Location: " + _name + "\n";
		}

		//Add item at the pointers vectors of Items
		void addItem( const std::string & theName, const int & level )
		{
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
			Item * anonymous = new Item ();
			
			anonymous->name("Hammer");
			anonymous->level(0u);
			_items.push_back(anonymous);
		
		}
		//Retorna tot el contingut del vector
		std::string items() const
		{
			for (Items::const_iterator it=_items.begin(); it!=_items.end(); it++)
				{
					return "Hola";
				}	
		}
};

//Location_hxx

#endif
