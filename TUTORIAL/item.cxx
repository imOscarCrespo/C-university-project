/*


PRACTICA 2:


	ALUMNES			NIA


 Xavier Maltas -> 183809

 Oscar Crespo -> 174888
*/


#ifndef items_hxx
#define items_hxx
//PER PODER UTILITZAR TANT VECTORS I STRINGS A LA PRACTICA HEM HAGUT D'AFEGIR ELS INCLUDES NECESARIS
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

//Classe Item
class Item
{
    public: 
	//setter de la variable name
    	void name(std::string theName){
    		_name = theName;
    	}
	//getter de la variable name
    	std::string& name(){
    		return _name;
    	}
	//setter de la variable level
	void level(std::string theLevel){
    		_level = theLevel;
    	}
	//getter de la variable level
    	std::string& level(){
    		return _level;
    	}
   
    private:
	//declaracio de les variable name i level de la classe Item
    	std::string _name;
	std::string _level;
    };

#endif

typedef std::list<Item*> Items; //Declaració d'una llista anomenada Items de tipus Item(classe)

int main(void){
        
    Items items;  //Creació d'una instancia items de tipus Items

    	int N;
	int barSpace;
    	std::string line;
	std::string nomItem;
	std::string linewtbarSpace;
	std::string levell;

    std::cin>> N >> std::ws;  //std::cin llegeix i ho guarda a N el que entrem per pantalla (usuari), correspon al nombre d'iteracions haurem de fer en el for seguent

    for(int i = 0; i<N; i++){  //N es el numero que hem entrat per pantalla, i el nombre d'iteracions

        std::getline( std::cin, line); //guardem total la linia llegida a la variable line
        barSpace = line.find("-"); //Busquem la posició en la que es troba el caracter "-"
	linewtbarSpace = line.substr(barSpace); //Creem una linia, que es igual a la llegida, treient el caracter "-"
	nomItem = line.substr(0,barSpace); //El nom del item, es troba desdel inici de la linia llegida fins la posició del caracter "-"
	levell = linewtbarSpace.substr(1); //El valor del nivell, va desdel caracter "-" fins al final
	Item *Itemm = new Item(); //Instancia d'una nou item
	//Atribució del valors name i level a la instancia
	Itemm->name(nomItem); 
	Itemm->level(levell);
	//Posem la nova instancia plena al final de la llista
	items.push_back(Itemm);
    }

	//Recorrem tota la llista, i imprimim els valor demanats amb la estructura marcada
    for (Items::iterator it=items.begin(); it!=items.end(); it++){
        std::cout << "Item: " << (*it)->name() <<" ["<< (*it)->level()<<"]"<<std::endl;
    }

    return 0;

}

