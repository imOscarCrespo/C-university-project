/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

#ifndef WORLD_HXX
#define WORLD_HXX

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <exception>

#include "Location.hxx"
#include "Item.hxx"
#include "Exception.hxx"
#include "Character.hxx"



class World{
	std::string _name;

	typedef std::list<Location*> Locations;
	typedef std::list<Character*> Characters;


	public:

		Locations _locations;
		Characters _characters;

		World()
		//inicialització per defecte
			: _name("unknown")	

		{}
		//World Destructor
		~World()
		{
			for (Locations::const_iterator it =_locations.begin(); it!=_locations.end(); it++){
				delete (*it);
			}
		}

// ------------ WORLD 

	//Getter
		const std::string & name() const{
			return _name;
		}//name

	//Setter
		void name(const std::string &theName){
			_name = theName;
		}//name

// ------------ WORLD END

// ------------ LOCATION
		void addLocation(const std::string & theName){
			Location * anonymous = new Location ();
			anonymous->name(theName);
			_locations.push_back(anonymous);
		}//addLocation

		//Retorna totes les localitzacions del World
		std::string locations() const{
				string locations;

				for (Locations::const_iterator it=_locations.begin(); it!=_locations.end(); it++)
					{
						locations = locations + (*it)->name() + "\n";
					}

				return locations;
		}//locations

		//Reserca d'una localització dins del World i treure tota la seva infomació
		std::string locationDetails( const std::string & theLocation) const{
				for( Locations::const_iterator it=_locations.begin(); it!=_locations.end(); it++)
					{
						if(  (*it)->name() == theLocation  )
							{		
								return (*it)->description();						
							}
		
					}
			
				throw LocationNotFound();

		}//locationDetails

		std::string addItemAtLocation(const std::string & theLocation, const std::string & theItem, int level){
			
			for( Locations::const_iterator it= _locations.begin(); it!=_locations.end(); it++)
				{
					//Comprovacio si la localitzacio existeix
					if( (*it)->name() == theLocation)
						{
							//Afegim l'element a la localitzacio
							(*it)->addItem( theItem, level );
							return "Element added";
							
						}
				}
			throw LocationNotFound();

		}//addItemAtLocation


		Location & findLocation( const std::string &theLocation){
			if( _locations.empty() != true )
			{
				for( Locations:: const_iterator it = _locations.begin(); it != _locations.end(); it++)
				{
					if( (*it)->name() == theLocation )
						return (**it);
				}
			}
			throw LocationNotFound();
		}//findLocation


		void connectNorthToSouth( const std::string & theNorth, const std::string & theSouth){
		
			for( Locations::const_iterator it = _locations.begin(); it!=_locations.end(); it++)
			{
				if( (*it)->name() == theNorth )
				{	(*it)->connectSouth( findLocation( theSouth ) );	}

				if( (*it)->name() == theSouth )
				{
					(*it)->connectNorth(findLocation(theNorth));
				}

			}
		}//connectNorthToSouth


		void connectWestToEast( const std::string & theWest, const std::string & theEast){
		
			for( Locations::const_iterator it = _locations.begin(); it!=_locations.end(); it++)
			{
				if( (*it)->name() == theWest )
				{	(*it)->connectEast( findLocation( theEast ) );	}

				if( (*it)->name() == theEast )
				{
					(*it)->connectWest(findLocation(theWest));
				}

			}
		}//connectWestToEast

// ------------ LOCATION END

// ------------ CHARACTERS
		std::string characters() const{

			for (Characters::const_iterator it=_characters.begin(); it!=_characters.end(); it++)
				{
					if ( (*it) == NULL){
						return "";
					}

					else {

							std::string aux;
							int r;
							for(r = 0; r < _characters.size(); r++){
								aux = aux + (*it)->name() + "\n";
								it++;
							}
							return aux;
							//return "\tItem: " + (*it)->name() + " [" + cadena + "]\n";
					}

				}

			return "";
		}//characters

		void addCharacter( const std::string & theName, const int & level){
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
			Character * anonymous = new Character();
			
			anonymous->name(theName);
			anonymous->level(level);
			_characters.push_back( anonymous);

		}//addCharacter

		void placeCharacter(const std::string & theCharacter, const std::string & theLocation){

			Character* anonymous = NULL;

			for( Locations::const_iterator it1 = _locations.begin(); it1!= _locations.end(); it1++ )
			{
				if( (*it1)->name() == theLocation )
					{
						for( Characters::const_iterator it2 = _characters.begin(); it2!= _characters.end(); it2++)
						{
							if( (*it2)->name() == theCharacter) 
							{
								anonymous = (*it2);
								(*it1) ->placeCharacter(*anonymous);
								//break;
							}
						}
						//break;
					}
			}
			if( anonymous == NULL)
				throw CharacterNotFound();

		}//placeCharacter

// ------------ CHARACTERS END

};





#endif
