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
#include "Character.hxx"


class Location{

//ATRIBUTS d'entrada
std::string _name;
std::string _north;
std::string _south;
std::string _east;
std::string _west;
//
typedef std::list<Item*> Items;
typedef std::list<Character*> Characters;

public:
	//Llista d'Items
	Items _items;
	//Llista d'Items
	Characters _character;
	//Constructor de la classe

	Location()
		//inicialització per defecte
		: _name("unknown")
		
	{}


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
		const std::string & north() const
		{
			return _north;
		}
		void north(const std::string &theNorth)
		{
			_north = theNorth;
		}

		//SOUTH
		const std::string & south() const
		{
			return _south;
		}
		void south(const std::string &theSouth)
		{
			_south = theSouth;
		}
		//EAST
		const std::string & east() const
		{
			return _east;
		}
		void east(const std::string &theEast)
		{
			_east = theEast;
		}

		//WEST
		const std::string & west() const
		{
			return _west;
		}
		void west(const std::string &theWest)
		{
			_west = theWest;
		}


		//Empty Description
		std::string description() const
		{
			return "Location: " + _name + "\n" + items() + characters();

		}

/*----------------------------------CONNECTIONS----------------------------------------*/
		std::string connections() const
		{
			return "\tNorth: " + north()+ "\n"+ "\tSouth: " + south() + "\n";
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
	
			throw Exception1();			

		}

		void unplaceCharacter(Character &theCharacter){

			Character * anonymous = new Character();
			anonymous = &(theCharacter);

			_character.remove(anonymous);

		}

		





};

//Location_hxx

#endif
