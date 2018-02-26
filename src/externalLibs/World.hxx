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
							if( (*it)->name() == theLocation ){		
								return "Location: " + (*it)->name() + "\n";						
							}
					}
			
				throw LocationNotFound();

			}

};













#endif
