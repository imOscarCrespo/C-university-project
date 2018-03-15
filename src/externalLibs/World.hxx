/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

#ifndef WORLD_HXX
#define WORLD_HXX

// #include <iostream>
// #include <string>
// #include <list>
// #include <algorithm>
#include <vector>
// #include <exception>

#include "Location.hxx"
#include "Item.hxx"
#include "Exception.hxx"
#include "Character.hxx"

typedef std::list<Location*> Locations;
typedef std::list<Character*> Characters;

class World{
	std::string _name;

	
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

			for (Characters::const_iterator it = _characters.begin(); it!=_characters.end(); it++){
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

		void addCharacter( const std::string & theName, const int & theLevel){
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
			Character * anonymous = new Character();
			
			anonymous->name(theName);
			anonymous->level(theLevel);
			_characters.push_back( anonymous);

			delete anonymous;

		}//addCharacter

		void placeCharacter (const std::string &character,const std::string &location){
			int flagCheckCharacter = 0;
			for (Characters::const_iterator it = _characters.begin();it != _characters.end();it++ ){
				if((*it)->name() == character){
					findCharacter(character).locateAt(findLocation(location));
					flagCheckCharacter=1;
				}
			}
			if(flagCheckCharacter==0){throw CharacterNotFound();}
		}//placeCharacter


		Character & findCharacter ( const std::string & character ){
			if ( _characters.empty() != true )
			{	
				for ( Characters::iterator it = _characters.begin(); it != _characters.end(); ++it )
					if( (*it)->name() == character )
						return (**it);
			}
 
			throw CharacterNotFound();
		}//findCharacter

// ------------ CHARACTERS END


// ------------ ITEM 

		std::string useItem(const std::string theLocation, const std::string theCharacter, const std::string theItem){
			
			//Check if the Location exists or not
			findLocation(theLocation);

			//Check if the Charachter exists or not
			findCharacter(theCharacter);

			//Check if the Item exists or not in theLocation
			findLocation(theLocation).findItem(theItem);

			//Check if the level of theCharacter is high enogh to use theItem
			if( ( findCharacter(theCharacter).level() ) >= ( findLocation(theLocation).findItem(theItem).level())   ){
				return "hola";
			}
			else{
				return "The level of " + findCharacter(theCharacter).name() + " is too low\n";
			}



		}//useItem

// ------------ ITEM END

};





#endif
