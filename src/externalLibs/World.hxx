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
#include <iostream>
#include <vector>



class World{
	std::string _name;

	typedef std::list<Location*> Locations;
	typedef std::list<Character*> Characters;


	public:

		Locations _locations;
		Characters _characters;

		World()
		//inicialització per defecte
		//: _name("unknown")	

		{}
		~World()
		{
			for (Locations::const_iterator it =_locations.begin(); it!=_locations.end(); it++){
				delete (*it);
			}
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

		void addLocation(const std::string & theName){

			Location * anonymous = new Location ();
			//Sha d'utilitzar la funcio location.description
			anonymous->name(theName);
			_locations.push_back(anonymous);
		}

		//Retorna totes les localitzacions del World
		std::string locations() const
			{

				for (Locations::const_iterator it=_locations.begin(); it!=_locations.end(); it++)
					{
						if ( (*it) == NULL){
							return "";
						}

						else {
								std::string aux;
								int r;
								for(r = 0; r < _locations.size(); r++){
									aux = aux + (*it)->name() + "\n";
									it++;
								}
								return aux;
								//return "\tItem: " + (*it)->name() + " [" + cadena + "]\n";
						}

					}

				return "";
			}

		//Reserca d'una localització dins del World i treure tota la seva infomació
		std::string locationDetails( const std::string & theLocation) const
			{
				for( Locations::const_iterator it=_locations.begin(); it!=_locations.end(); it++)
					{
						if(  (*it)->name() == theLocation  )
							{		
								return (*it)->description();						
							}
		
					}
			
				throw LocationNotFound();

			}

		std::string addItemAtLocation(const std::string & theLocation, const std::string & theItem, int level)
			{
			
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


			} 


		Location & findLocation( const std::string &theLocation)
		{
			if( _locations.empty() != true )
			{
				for( Locations:: const_iterator it = _locations.begin(); it != _locations.end(); it++)
				{
					if( (*it)->name() == theLocation )
						return (**it);
				}
			}
			throw LocationNotFound();
		}


		void connectNorthToSouth( const std::string & theNorth, const std::string & theSouth)
		{
		
			for( Locations::const_iterator it = _locations.begin(); it!=_locations.end(); it++)
			{
				if( (*it)->name() == theNorth )
				{	(*it)->connectSouth( findLocation( theSouth ) );	}

				if( (*it)->name() == theSouth )
				{
					(*it)->connectNorth(findLocation(theNorth));
				}

			}
		}


		void connectWestToEast( const std::string & theWest, const std::string & theEast)
		{
		
			for( Locations::const_iterator it = _locations.begin(); it!=_locations.end(); it++)
			{
				if( (*it)->name() == theWest )
				{	(*it)->connectEast( findLocation( theEast ) );	}

				if( (*it)->name() == theEast )
				{
					(*it)->connectWest(findLocation(theWest));
				}

			}
		}


		std::string characters() const
		{
			for (Characters::const_iterator it=_characters.begin(); it!=_characters.end(); it++)
				{
					if ( (*it) == NULL){
						return "";
					}

					else {

							std::string aux;
							int r;
							for(r = 0; r < _characters.size(); r++){
								aux = (*it)->name() + " \n";
								it++;
							}
							return aux;
							//return "\tItem: " + (*it)->name() + " [" + cadena + "]\n";
					}

				}

			return "";

		}

		void addCharacter( const std::string & theName, const int & level )
		{
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
			Character * anonymous = new Character();
			
			anonymous->name(theName);
			anonymous->level(level);
			_characters.push_back(anonymous);

			delete anonymous;
		
		}


};













#endif
