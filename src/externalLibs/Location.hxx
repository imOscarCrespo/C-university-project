/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

//Location.hxx

#ifndef LOCATION_HXX
#define LOCATION_HXX

class Location{

//ATRIBUTS d'entrada
std::string _name;
//std::string _description;

public:

//Constructor de la classe

	Location()
		//inicialització per defecte
		: _name("unknown")
		//,
		//
		
	{

		 
	}


//Metodes de la classe
		//Getter de name
		const std::string & name() const
		{
			return _name;
		}

	
};

//Location_hxx

#endif