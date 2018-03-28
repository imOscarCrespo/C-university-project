#ifndef AbstractItem_hxx
#define AbstractItem_hxx

#include "Character.hxx"
#include <iostream>
#include <string>
#include <vector>


class AbstractItem{

	public:
		virtual ~AbstractItem() {};
		virtual const std::string & getName() const = 0;
		virtual void setName(const std::string &name) = 0;
		virtual const unsigned int & level() const= 0;
		virtual void level(const unsigned int &level) = 0;
		virtual const bool & hasItem() const= 0;
		virtual void hasItem(const bool &hasItem) = 0;
		virtual std::string description () = 0;
		virtual std::string receiveMagic(const unsigned int points)= 0;
		virtual std::string useItem ( Location * newLocation, Character * newCharacter )= 0;
		virtual bool hasMagic () =0;
		virtual void hasMagic ( bool hasMagic ) =0;
};

#endif
