/*


PRACTICA 2:


	ALUMNES			NIA


 Xavier Maltas -> 183809

 Oscar Crespo -> 174888
*/


#ifndef locations_hxx
#define locations_hxx
//PER PODER UTILITZAR TANT VECTORS I STRINGS A LA PRACTICA HEM HAGUT D'AFEGIR ELS INCLUDES NECESARIS
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
    
class Location
{
    public: 
    	void name(std::string theName){
    		_name = theName;
    	}
    	std::string& name(){
    		return _name;
    	}
   
    private:
    	std::string _name;
    };

#endif

typedef std::list<Location*> Locations; //Declaració d'una llista anomenada Locations de tipus Animal(super-classe)

int main(void){
        
    Locations locations;  //Creació d'una instancia animals de tipus Animals

    	int N;
    	std::string line;
	std::string nomLoc;

    std::cin>> N >> std::ws;  //std::cin llegeix i ho guarda a N el que entrem per pantalla (usuari)

    for(int i = 0; i<N; i++){  //N es el numero que hem entrat per pantalla
        std::getline( std::cin, line); //guardem total la linia llegida a la variable line
        nomLoc = line.substr(0);
	Location *nomLocc = new Location();
	nomLocc->name(nomLoc);
	locations.push_back(nomLocc);
    }


    for (Locations::iterator it=locations.begin(); it!=locations.end(); it++){
        std::cout << "Location: " << (*it)->name() <<std::endl;
    }

    return 0;

}

