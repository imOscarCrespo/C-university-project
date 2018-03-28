#ifndef ITEM_HXX
#define ITEM_HXX 

#include <sstream>
#include "AbstractItem.hxx"

class Location;
class Character;

class Item : public AbstractItem{

	protected:
		std::string _name;
		unsigned int _level;
		bool _hasItem;
		bool _hasMagic;

	public:
		Item() 
			:_name("unknown"), 	
			 _level(50u),	   	
			 _hasItem(false)	

		{}	

/*-----------------------NAME------------------------*/	
		const std::string & getName() const{
			return _name;
		}//getName

		void setName(const std::string &name){
			_name = name;
		}//setName

/*-----------------------LEVEL------------------------*/	
		const unsigned int & level() const{
			return _level;
		}//level

		void level(const unsigned int &level){
			_level = level;
		}//level
		
/*-----------------------HAS ITEM------------------------*/	
		const bool & hasItem() const{
			return _hasItem;
		}//hasItem

		void hasItem(const bool &hasItem){
			_hasItem = hasItem;
		}//hasItem

		bool hasMagic () { 
			return _hasMagic; 
		}//hasMagic

		void hasMagic ( bool hasMagic ){ 
			_hasMagic = hasMagic; 
		}//hasMagic
		
/*-----------------------DESCRIPTION------------------------*/	
		std::string description (){
       		 	std::stringstream ss;
        		ss << getName() << " [" << level() << "]";
         		return ss.str();
   		}//description
/*-----------------------MAGIC------------------------*/	
		std::string receiveMagic(const unsigned int points){
			std::stringstream devolver;
			devolver << getName() << " receives " << points <<" magic points\n";
			hasMagic(true);
			return devolver.str();
			
		}//receiveMagic

		std::string useItem ( Location * newLocation, Character * newCharacter );
		

};
 

#endif
