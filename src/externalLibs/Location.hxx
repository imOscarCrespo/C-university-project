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
#include <exception>

#include "Item.hxx"
#include "Exception.hxx"
//#include "Character.hxx"


class Location{

//ATRIBUTS d'entrada
std::string _name;
Location *_north;
Location *_south;
Location * _east;
Location * _west;

//
typedef std::list<Item*> Items;
//typedef std::list<Character*> Characters;

public:
	//Llista d'Items
	Items _items;
	//Llista d'Items
	//Characters _character;
	//Constructor de la classe

	Location()
		//inicialització per defecte
		: _name("unknown")
		
	{
		_north = NULL;
		_south = NULL;
		_east = NULL;
		_west = NULL;
	}
	~Location()
	{
		for (Items::const_iterator it =_items.begin(); it!=_items.end(); it++){
			delete (*it);
		}

		/*for (Characters::const_iterator it =_character.begin(); it!=_character.end(); it++){
			delete (*it);
		}*/
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

		//NORTH
		Location* north()
		{
			return _north;
		}
		void connectNorth(Location & theNorth)
		{
			_north = &theNorth;
		}

		//SOUTH
		Location* south()
		{
			return _south;
		}
		void connectSouth(Location & theSouth)
		{
			_south = &theSouth;
		}
		

		//WEST
		Location* west()
		{
			return _west;
		}
		void connectWest(Location & theWest)
		{
			_west = &theWest;
		}

		//EAST
		Location* east()
		{
			return _east;
		}
		void connectEast(Location & theEast)
		{
			_east = &theEast;
		}
		

		//Empty Description
		std::string description()
		{
			return "Location: " + _name + "\n" + items() //+ characters() 
				+ connections();

		}

/*----------------------------------CONNECTIONS----------------------------------------*/
		std::string connections() const
		{
			std::string connections = "";
			if(_north != NULL)
			{

				connections = connections + "\tNorth: " + _north->name() + "\n";
			}
			
			if(_south != NULL)
			{	
				
				connections = connections + "\tSouth: " + _south->name() + "\n";
			}

			if(_east != NULL)
			{

				connections = connections + "\tEast: " + _east->name() + "\n";
			}
			
			if( _west != NULL)
			{	
				
				connections = connections + "\tWest: " + _west->name() + "\n";
			}
		
			return connections;
		}
/*----------------------------------ITEMS----------------------------------------------*/
		//Add item at the pointers vectors of Items
		void addItem( const std::string & theName, const int & level )
		{
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
			Item * anonymous = new Item ();
			
			anonymous->name(theName);
			anonymous->level(level);
			_items.push_back(anonymous);

			delete anonymous;
		
		}

		//Retorna tot el contingut del vector
		std::string items() const
		{

			for (Items::const_iterator it=_items.begin(); it!=_items.end(); it++)
				{
					if ( (*it) == NULL){
						return "";
					}

					else {

							int entero = (*it)->level();
							std::string cadena = "";
							cadena = std::to_string(entero);

							std::string aux;
							int r;
							for(r = 0; r < _items.size(); r++){
								aux = aux + "\tItem: " + (*it)->name() + " [" + cadena + "]\n";
								it++;
							}
							return aux;
							//return "\tItem: " + (*it)->name() + " [" + cadena + "]\n";
					}

				}

			return "";
		}

		//Retorna la posició de memoria d'on esta un item amb un nom concret que reps per parmentre
		Item & findItem(const std::string theName) const
		{
			
			Item *anonymous;
			
			for( Items::const_iterator it=_items.begin(); it!=_items.end(); it++)
			{
					if( (*it)->name() == theName ){		
						return *(*it);						
					}
			}
	
			throw Exception();			

		}
/*--------------------------------CHARACTER----------------------------------*/
/*
		void placeCharacter(Character &theCharacter){

			Character * anonymous = new Character();
			anonymous = &(theCharacter);

			_character.push_back(anonymous);

		}

		std::string characters() const
		{
			for (Characters::const_iterator it=_character.begin(); it!=_character.end(); it++)
				{
					if ( (*it) == NULL){
						return "";
					}

					else {

							std::string aux;
							int r;
							for(r = 0; r < _character.size(); r++){
								aux = aux + "- "  + (*it)->name() + " is here.\n";
								it++;
							}
							return aux;
							//return "\tItem: " + (*it)->name() + " [" + cadena + "]\n";
					}

				}

			return "";

		}

		Character & findCharacter(const std::string theName) const
		{
			
			Character *anonymous;
			
			for( Characters::const_iterator it=_character.begin(); it!=_character.end(); it++)
			{
					if( (*it)->name() == theName ){		
						return *(*it);						
					}
			}
	
			throw CharacterNotFound();			

		}

		void unplaceCharacter(Character &theCharacter){

			Character * anonymous = new Character();
			anonymous = &(theCharacter);

			_character.remove(anonymous);

		}

		

*/



};

//Location_hxx

#endif
