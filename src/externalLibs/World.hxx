#ifndef WORLD_HXX
#define WORLD_HXX
#include "Item.hxx"
#include "Character.hxx"
#include "Location.hxx"
#include "MyException.hxx"
//#include "gui/Model.hxx"
#include <vector>
#include <iostream>

typedef std::vector<Location *> Locations; 
typedef std::vector<Character *> Characters; 

class World /*: public Model*/{
	
	private:
	Locations _locations;
	Characters _characters;

	public:
		Character* player;
		
		World()
		{
		}

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
		std::string locationDetails( const std::string & theCharacter){
			
			std::string locations;
			
			for ( Locations::const_iterator it = _locations.begin(); it != _locations.end(); it++ ){
				
				if ((*it)->name() == theCharacter){
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
		void addCharacter (const std::string & newCharacter, unsigned int level){
			//nova instancia de item
			//set del valors de la nova instancia
			//pushback al final del vector
		
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
			//El character utilitza el item a la localitzacio			
		
			std::string output;

			findLocation(location); 
			findCharacter(character); 
			findLocation(location).findItem(item); 
			output = findLocation(location).useItem(character,item);

			return output;

		}//useItem

		std::string distributeMagic (const std::string &location, const unsigned int points){
			std::string output;

			findLocation(location);
			output = findLocation(location).distributeMagic(points);

			return output;

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

//---------------------GUI-----------------------//

		void registerPlayer( const std::string & playerName ){
			//registrem el jugador i l'afegim a la llista de caracter dins la seva localitzacio

			player = new Character();
			player->name(playerName);
			_characters.push_back( player );
		}

		std::string locationDetails(){
			//return the name of the current Location of the player Character
			return player->currentLocation()->name();
		}

		void move( const std::string & direction ){
			//Fem que el jugador es mogui d'un lloc a un altre
			Location* neighbourLocation = player->currentLocation()->neighbor(direction);
			player->currentLocation( neighbourLocation );		
		}

		std::string useItem( const std::string & itemName ){
			//El player utilitza el item anomenat

			std::string output;
			findLocation( player->currentLocation()->name() );
			findCharacter( player->name() );
			player->currentLocation()->findItem( itemName );
			
			output = player->currentLocation()->useItem( player->name(), itemName );
			
			
			return output;
			//output: El jugador utilitzar el item a la location..
		
		}

};

#endif
