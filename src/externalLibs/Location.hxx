/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

//Location.hxx

#ifndef LOCATION_HXX
#define LOCATION_HXX

#include <iostream>
#include <string>
#include <list>
// #include <algorithm>
#include <vector>
// #include <exception>

#include "Item.hxx"
#include "Exception.hxx"
#include "Character.hxx"

typedef std::list<Item*> Items;
typedef std::list<Character*> Characters;

class Location{

	//ATRIBUTS d'entrada
	std::string _name;
	Location *_north;
	Location *_south;
	Location * _east;
	Location * _west;

	

	public:

		Items _items;
		Characters _character;

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
	
		~Location(){
			for (Items::const_iterator it =_items.begin(); it!=_items.end(); it++){
				delete (*it);
			}

			for (Characters::const_iterator it =_character.begin(); it!=_character.end(); it++){
				delete (*it);
			}
		}//~Locations


	//Metodes de la classe
		// -- NAME
			//Getter
				const std::string & name() const{
					return _name;
				}//name

			//Setter
				void name(const std::string &theName){
					_name = theName;
				}//name

		//-- NORTH
			Location* north(){
				return _north;
			}//north

			void connectNorth(Location & theNorth){
				_north = &theNorth;
			}//connectNorth

		//-- SOUTH
			Location* south(){
				return _south;
			}//south

			void connectSouth(Location & theSouth){
				_south = &theSouth;
			}//connectSouth

		//-- WEST
			Location* west(){
				return _west;
			}//west

			void connectWest(Location & theWest){
				_west = &theWest;
			}//connectWest

		//-- EAST
			Location* east(){
				return _east;
			}//east

			void connectEast(Location & theEast){
				_east = &theEast;
			}//connectEast
		// -- DESCRIPTION
			std::string description(){
				return "Location: " + _name + "\n" + connections() + items() + characters();
			}//description

		//RETURN DELS LISTS
			list<Character*> llistaCharacters(){
				return _character;
			}
			list<Item*> llistaItems(){
				return _items;
			}

/*----------------------------------CONNECTIONS--------------------------------*/

		std::string connections() const{
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
		}//connections

/*------------------------------------ITEMS------------------------------------*/

		void addItem( const std::string & theName, const int & level ){
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
			Item * anonymous = new Item ();
			
			anonymous->name(theName);
			anonymous->level(level);
			_items.push_back(anonymous);

			delete anonymous;
		
		}//addItem

		//Retorna tot el contingut del vector
		std::string items() const{

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
		}//itemss

		//Retorna la posició de memoria d'on esta un item amb un nom concret que reps per parmentre
		Item & findItem(const std::string theName) const{
			
		
			for( Items::const_iterator it=_items.begin(); it!=_items.end(); it++)
			{
					if( (*it)->name() == theName ){		
						return *(*it);						
					}
			}
	
			throw ItemNotFound();			

		}//findItem


		void useItem(const std::string theLocation, const std::string theCharacter, const std::string theItem){

			
			findCharacter(theCharacter);

			findItem(theItem);

			//Retorna la instancia de tipus Item que te com a nom theItem
			//Item & anonymousItem = findItem(theItem);
			//Retorna la instancia de tipus Character que te com a nom theCharacter
			//Character & anonymousChar = findCharacter(theCharacter);

		}//useItem

/*----------------------------------CHARACTER----------------------------------*/

		void placeCharacter(Character &theCharacter){
			_character.push_back(&theCharacter);
		}//placeCharacter

		std::string characters() const{
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

		}//characters

		Character & findCharacter(const std::string theName) const{
			//Character *anonymous;
			
			for( Characters::const_iterator it=_character.begin(); it!=_character.end(); it++)
			{
					if( (*it)->name() == theName ){		
						return *(*it);						
					}
			}
	
			throw CharacterNotFound();			
		}//findCharacter

		void unplaceCharacter(Character &theCharacter){
			_character.remove(&theCharacter);
		}//unplaceCharacter


};

//Location_hxx

#endif
