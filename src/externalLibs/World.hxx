#ifndef WORLD_HXX
#define WORLD_HXX
#include "Item.hxx"
#include "Character.hxx"
#include "Location.hxx"
#include "MyException.hxx"
#include <vector>
#include <iostream>

typedef std::vector<Location *> Locations; 
typedef std::vector<Character *> Characters; 

class World{
	
	private:
	Locations _locations;
	Characters _characters;

	public:

		
		World(){}
		//World Destructor
		~World(){
			for(Locations::iterator it = _locations.begin(); it!= _locations.end(); it++){
				delete *it;
			}
			for(Characters::iterator it = _characters.begin(); it!= _characters.end(); it++){
				delete *it;
			}
		}


// ------------ LOCATION

		void addLocation (const std::string & newLocation)
		{
			Location* location = new Location();
			location->name(newLocation);
			_locations.push_back(location);
		}//addLocation
	
		//Retorna totes les localitzacions del World
		std::string locations () const
		{
			std::string locations = "";
	
			for ( Locations::const_iterator it = _locations.begin(); it != _locations.end(); it++ ){
				locations += (*it)->name() + "\n";
			}
	
			return locations;
		}
		//Reserca d'una localització dins del World i treure tota la seva infomació
		std::string locationDetails( const std::string & details){
			
			std::string locations;
			
			for ( Locations::const_iterator it = _locations.begin(); it != _locations.end(); it++ ){
				
				if ((*it)->name() == details){
					locations += (*it)->description();
					return locations; 
				}
			}
			throw LocationNotFound();
		}

		void addItemAtLocation(const std::string &newLocation, const std::string &newItem2, unsigned requiredLevel){
			bool aux= false;
			for ( Locations::const_iterator it = _locations.begin(); it != _locations.end(); it++ ){
				
				if ((*it)->name() == newLocation){
					(*it)->addItem(newItem2, requiredLevel);
					aux = true;
				}
			}
			if(aux==false) {throw LocationNotFound();}
		
		}

		void connectNorthToSouth(const std::string &north, const std::string &south){

			for ( Locations::const_iterator it = _locations.begin(); it != _locations.end(); it++ ){
				if ((*it)->name() == north){(*it)->connectSouth(findLocation(south));}
				if ((*it)->name() == south){(*it)->connectNorth(findLocation(north));}
			}	
			
		}//connectNorthToSouth
		
		void connectWestToEast(const std::string &west, const std::string &east){

			for ( Locations::const_iterator it = _locations.begin(); it != _locations.end(); it++ ){
				if ((*it)->name() == west){(*it)->connectEast(findLocation(east));}
				if ((*it)->name() == east){(*it)->connectWest(findLocation(west));}	
			}	
			
		}
		
		
		Location & findLocation ( const std::string & newLocation )
		{
			if ( _locations.empty() != true )
			{	
				for ( Locations::iterator it = _locations.begin(); it != _locations.end();++it )
					if( (*it)->name() == newLocation )
						return (**it);
			}

			throw LocationNotFound();
		}//findLocation


// ------------ CHARACTERS
		void addCharacter (const std::string & newCharacter, unsigned int level)
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
		{
			Character* character = new Character();
			character->name(newCharacter);
			character->level(level);
			_characters.push_back(character);
		}//addCharacter
		
		std::string characters()const
		{
			std::string characters = "";
	
			for (Characters::const_iterator it = _characters.begin();it != _characters.end();it++ ){
				characters += (*it)->name() + "\n";
			}
	
			return characters; 
		}

		void placeCharacter (const std::string &character,const std::string &location)
		{
			int aux = 0;
			for (Characters::const_iterator it = _characters.begin();it != _characters.end();it++ ){
				if((*it)->name() == character){
					findCharacter(character).locateAt(findLocation(location));
					aux=1;
				}
			}
			if(aux==0){throw CharacterNotFound();}
		}


		Character & findCharacter ( const std::string & character )
		{
			if ( _characters.empty() != true )
			{	
				for ( Characters::iterator it = _characters.begin(); it != _characters.end(); ++it )
					if( (*it)->name() == character )
						return (**it);
			}
 
			throw CharacterNotFound();
		}
// ------------ CHARACTERS END
// ------------ ITEM 
	
		std::string useItem(const std::string & location, const std::string & character, const std::string & item){
			std::string devolver;
			findLocation(location); 
			findCharacter(character); 
			findLocation(location).findItem(item); 
			devolver=findLocation(location).useItem(character,item);
			return devolver;
		}//useItem

		std::string distributeMagic (const std::string &location, const unsigned int points){
			std::string devolver;
			findLocation(location);
			devolver=findLocation(location).distributeMagic(points);
			return devolver;
		}//distributeMagic

		void addDamageCharacter(const std::string &character,const unsigned int points){

			Character* damageChar = new DamageCharacter(character,points);
			_characters.push_back(damageChar);		

		}

		void addTrapAtLocation(const std::string &location, const std::string &trap, const unsigned int points){
		
			findLocation(location).addTrap(trap,points); 
		}

		void addCureCharacter(const std::string &character,const unsigned int points){

			Character* cureChar = new CureCharacter(character,points);
			_characters.push_back(cureChar);		

		}

		void addPotionAtLocation(const std::string &location, const std::string &trap, const unsigned int points){
		
			findLocation(location).addPotion(trap,points); 
		}

		void addBombAtLocation(const std::string &location, const std::string &bomb, const unsigned int points)
		{
			findLocation(location).addBomb(bomb,points); 
		}

};

#endif
