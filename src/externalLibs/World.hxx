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


	public:

		Locations _locations;

		World()
		//inicialització per defecte
		//: _name("unknown")	

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
							if( ( (*it)->name() == theLocation ) && (  (*it)->north() != "" || (*it)->south() != "" ) ){		
								return (*it)->description_ns();						
							}

							if( ( (*it)->name() == theLocation ) && (  (*it)->north() == "" || (*it)->south() == "" ) )
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

		void connectNorthToSouth( const std::string & theNorth, const std::string & theSouth)
			{
			
				for( Locations::const_iterator it1=_locations.begin(); it1!=_locations.end();it1++)
				{
					if( (*it1)->name() == theNorth )
					{
						for( Locations::const_iterator it2=_locations.begin(); it2!=_locations.end();it2++)
						{
							if( (*it2)->name() == theSouth )
							{
								(*it1)->south( theSouth);
								(*it2)->north( theNorth);
							}
						}
					}


				}
			}


};













#endif
