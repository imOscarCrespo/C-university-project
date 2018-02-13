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

//Classe Location
class Location
{
    public: 
	//Setter de la variable name
    	void name(std::string theName){
    		_name = theName;
    	}	
	//Getter de la variable name
    	std::string& name(){
    		return _name;
    	}
   
    private:
	//Declaració de la variable name
    	std::string _name;
    };

#endif

typedef std::list<Location*> Locations; //Declaració d'una llista anomenada Locations de tipus Location(Classe)

int main(void){
        
    Locations locations;  //Creació d'una instancia locations del tipus Locations

    	int N;
    	std::string line;
	std::string nomLoc;

    std::cin>> N >> std::ws;  //std::cin llegeix i ho guarda a N el que entrem per pantalla (usuari)

    for(int i = 0; i<N; i++){  //N es el numero que hem entrat per pantalla, i el nombre d'iteracions
        std::getline( std::cin, line); //guardem total la linia llegida a la variable line
        nomLoc = line.substr(0); //El nom de la localitzacio correspon al valor de tota la linia llegida
	Location *nomLocc = new Location(); //Creació d'una nova instancia del tipus Location
	nomLocc->name(nomLoc); //Donem valor a la variable name mitjançant el setter de la classe Location
	locations.push_back(nomLocc); //Posem la nova instancia al final del vector d'instancies del tipus Location
    }

	//Recorrem tota la llista, i imprimim els valor demanats amb la estructura marcada
    for (Locations::iterator it=locations.begin(); it!=locations.end(); it++){
        std::cout << "Location: " << (*it)->name() <<std::endl;
    }

    return 0;

}

