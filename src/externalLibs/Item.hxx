/*
*	PRACTICA 3 : Xavier Maltas i Oscar Crespo
*/
//#include <Exception.hxx>

#ifndef ITEM_HXX
#define ITEM_HXX 

#include <sstream>
#include <string>
// #include "Exception.hxx"

class Item{

	std::string _name;
	int _level;
	bool _enable;

	public:
		Item()
			: _name("unknown"),
			_level(10u),
			_enable(false)
		{}

/*----------NAME-------------*/
		//Getter
			const std::string & name() const{
				return _name;
			}//name

		//Setter
			void name(const std::string &name){
				_name = name;
			}//name

/*----------LEVEL-------------*/
		//getter
			const int & level()  const{
				return _level;
			}//level

		//setter
			void level(const int & theLevel){
				_level = theLevel;
			}//level
		
/*----------ENABLE-------------*/
		//getter 
			const bool & enable() const{
				return _enable;
			}//enable

		//setter
			void enable( const bool & theEnable){
				_enable = theEnable;
			}//enable

/*---------DESCRIPTION----------*/

	std::string description() const{
		int entero = _level;
		std::string cadena = "";
		cadena = std::to_string(entero);

		return _name + " [" + cadena + "]";
	}//descripption


	std::string use(std::string theCharacter, std::string theLocation){
		return theCharacter + " uses " + (*this).name() + " at " + theLocation + "\n";
	}//use

	std::string receiveMagic (int magicPoint){
		return this->name() + " receives " + std::to_string(magicPoint) + " magic points\n";
	}

};



#endif
