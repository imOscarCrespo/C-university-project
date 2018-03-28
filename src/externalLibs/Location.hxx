#ifndef LOCATION_HXX
#define LOCATION_HXX

#include "Item.hxx"
#include "Character.hxx"
#include "MyException.hxx"
#include "DamageCharacter.hxx"
#include "CureCharacter.hxx"
#include "AbstractItem.hxx"
#include "TrapItem.hxx"
#include "PotionItem.hxx"
#include "BombItem.hxx"
#include <vector>
#include <sstream>

typedef std::vector<AbstractItem *> Items;
typedef std::vector<Character *> Characters;

class Location{

	std::string _name;
	Items _items;
	Characters _characters;

	Location* _north;
	Location* _south; 
	Location* _west;
	Location* _east;

	public:
		Location()
			:_name("unknown")
			
		{
		_north=NULL;
		_south=NULL;
		_west=NULL;
		_east=NULL;
		}	
			
		~Location(){
			for(Items::iterator it = _items.begin(); it!= _items.end(); it++){
				delete *it;
			}
		}	
/*-----------------------NAME------------------------*/	
		const std::string & name() const
		{
			return _name;
		}//name

		void name(const std::string &name) 
		{
			_name = name;
		}//name	

/*-----------------------DESCRIPTION------------------------*/	
		std::string description()
		{
			std::string description = "Location: " + _name + "\n";
			description += connections();
			description += items();
			description += characters();
			
			return description;	
		}//description
/*-----------------------CONNECTIONS------------------------*/	
		std::string connections () const 
		{
			std::string connections = "";

			if (_north != NULL ){connections += "\tNorth: " + _north->name() + "\n";}
			if (_south != NULL ){connections += "\tSouth: " + _south->name() + "\n";}
			if (_east != NULL ){connections += "\tEast: " + _east->name() + "\n";}
			if (_west != NULL ){connections += "\tWest: " + _west->name() + "\n";}

			return connections; 
		}//connections

/*-----------------------ITEMS------------------------*/	
		void addItem(const std::string &name, unsigned int level){
			AbstractItem* absItem = new Item();
			absItem->setName(name);
			absItem->level(level);
			_items.push_back(absItem);
		}//addItem

		std::string items() const{
			std::string out = "";
			for(Items::const_iterator it = _items.begin(); it!= _items.end(); it++){
				out += "\tItem: " + (*it)->description() + "\n";
			}
			return out;
			
		}//items
		

		AbstractItem & findItem(const std::string &findName){
			for(Items::const_iterator it = _items.begin(); it!= _items.end(); it++){
				if((*it)->getName() == findName){
					return (**it);			
				}
			}
			throw ItemNotFound();
			
		}//findItem
		
/*-----------------------CHARACTER------------------------*/	
		void placeCharacter(Character & placedCharacter){
			Character * characterPl = &placedCharacter;
			_characters.push_back( characterPl );
		}//placeCharacter


		std::string characters(){
			std::string characters;

			for(Characters::iterator it = _characters.begin(); it != _characters.end(); ++it){
				characters += "- " + (*it)->name() + " is here.\n";
			}
			return characters;
		}//characters
		
	
		Character & findCharacter(const std::string &findName){
			for(Characters::iterator it = _characters.begin(); it!= _characters.end(); it++){
				if((*it)->name() == findName){
					return (**it);			
				}
			}
			throw CharacterNotFound();
			
		}//findCharacter
		

		void unplaceCharacter(Character & unplacedCharacter){
			for(Characters::iterator it = _characters.begin(); it!= _characters.end(); it++){
				if((*it)->name() == unplacedCharacter.name()){
					it = _characters.erase(it);
					return;			
				}
			}
			throw CharacterNotFound();
			
		}//unplaceCharacter
		

/*-----------------------DIRECTIONS------------------------*/	
		void connectNorth(Location &norte){
			_north = &norte;
		}//connectNorth
		
		Location* north() {
			return _north;
		}//north

		void connectSouth(Location &sur){
			_south = &sur;
		}//connectSouth

		Location* south() {
			return _south;
		}//south

		void connectWest(Location &west){
			_west = &west;
		}//connectWest

		Location* west() {
			return _west;
		}//west
		
		void connectEast(Location &east){
			_east = &east;
		}//connectEast

		Location* east() {
			return _east;
		}//east	

/*-----------------------ITEMS AND MAGIC------------------------*/	
		std::string useItem(const std::string & character, const std::string & item){
			std::string retorno= character+" uses " +item + " at "+ _name+"\n";
			if(findCharacter(character).level()<findItem(item).level()){
				return "The level of " + character +" is too low\n";
			}
			retorno = findItem(item).useItem(this, &findCharacter(character));
			return retorno; 
		}//useItem
		
		std::string distributeMagic (const unsigned int points){
			std::string output;
			for(Characters::iterator it = _characters.begin(); it!= _characters.end(); it++){
			
				output += (*it)->receiveMagic(points);		
				
			}
			for(Items::const_iterator it = _items.begin(); it!= _items.end(); it++){
				output += (*it)->receiveMagic(points);
			}
			return output; 
			
		}//distributeMagic
		
		void removeItem(const std::string & remItem){
		    for(Items::iterator it = _items.begin(); it!= _items.end(); it++){
		        if((*it)->getName() == remItem){
		        	delete *it;
		            it = _items.erase(it);
		            return;
		        }
		    }
		    throw ItemNotFound();

		}//removeItem

		void addTrap(const std::string &trap, const unsigned int points){

			AbstractItem* absItem = new TrapItem(new Item());
			absItem->setName(trap);
			absItem->level(points);
			_items.push_back(absItem);
			
		}//addTrap

		void addPotion(const std::string &potion, const unsigned int points){

			AbstractItem* absItem = new PotionItem(new Item());
			absItem->setName(potion);
			absItem->level(points);
			_items.push_back(absItem);
			
		}//addPotion

		void addBomb(const std::string &bomb, const unsigned int points){
			
			AbstractItem* absItem = new BombItem(new Item());
			absItem->setName(bomb);
			absItem->level(points);
			_items.push_back(absItem);
			
		}//addBomb
		
//---------------------GUI-----------------------//

		Location* neighbor(std::string theDirection){
			if( theDirection == "north" )
				return _north;
			if( theDirection == "south" )
				return _south;
			if( theDirection == "west" )
				return _west;
			if( theDirection == "east" )
				return _east;
		}


};


#endif
