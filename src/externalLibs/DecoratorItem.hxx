#ifndef DecoratorItem_hxx
#define DecoratorItem_hxx

#include "AbstractItem.hxx"
#include <iostream>
#include <string>
#include <list>
#include <vector>

class DecoratorItem : public AbstractItem {

	protected:
		AbstractItem* _absItem;

	public:
		DecoratorItem (AbstractItem * item){
			_absItem = item;
		}

		~DecoratorItem(){
			if ( _absItem != NULL ) {
				delete _absItem; 
			}
		}
/*-----------------------NAME------------------------*/	
		const std::string & getName() const{
			return _absItem->getName();
		}//getName

		void setName(const std::string &name){
			return _absItem->setName(name);
		}//setName

/*-----------------------LEVEL------------------------*/	
		const unsigned int & level() const{
			return _absItem->level();
		}//level

		void level(const unsigned int &level){
			return _absItem->level(level);
		}//level
		
/*-----------------------HAS ITEM------------------------*/	
		const bool & hasItem() const{
			return _absItem->hasItem();
		}//hasItem

		void hasItem(const bool &hasItem){
			return _absItem->hasItem(hasItem);
		}//hasItem

/*-----------------------HAS MAGIC------------------------*/	
		bool hasMagic () { 
			return _absItem->hasMagic(); 
		}//hasMagic

		void hasMagic ( bool hasMagic ) { 
			return _absItem->hasMagic(hasMagic); 
		}//hasMagic

/*-----------------------DESCRIPTION------------------------*/	
		std::string description (){
       			return _absItem->description();
   		}//description

/*-----------------------RECEIVE MAGIC------------------------*/	
		std::string receiveMagic(const unsigned int points){
			return _absItem->receiveMagic(points);
		}//receiveMagic

/*-----------------------USE ITEM------------------------*/	
		std::string useItem ( Location * newLocation, Character * newCharacter ){
			return _absItem->useItem(newLocation, newCharacter);
		}//useItem

};

#endif
