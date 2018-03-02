/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

#ifndef CHARACTER_HXX
#define CHARACTER_HXX
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <exception>

#include "Location.hxx"

class Character{

//ATRIBUTS d'entrada

std::string _name;
int _level;
int _life;
int _damage;
int _cure;
//Location * _location;


public:

//Constructor de la classe

	Character()
		//inicialització per defecte
		:	_name("unknown"), 
			_level(0u), 
			_life(10u)

	{
		//_location = NULL;
	}

	~Character()
	{}



//Functions of the class
/*----------NAME-------------*/

	//getter
	const std::string & name() const //utilitzem & com a punter i cap persona des d'una altra part del codi no pot canviar aquest valor que guardem a _name, per tant ha de ser constant.
	{
		return _name;
	}

	//setter
	void name(const std::string & theName){
		_name = theName;
	}

/*----------LEVEL-------------*/
	//getter
	 const int & level()  const
	{
		return _level;
	}
	//setter
	void level(const int & theLevel){
		_level = theLevel;
	}
/*----------LIFE-------------*/
	const int & life()  const
	{
		return _life;

	}

	void life(const int & theLife){
		_life = theLife;
	}
/*----------DAMAGE-------------*/
	void damage(const int & theDamage){
		if(_life < theDamage){
			_life = 0;
		}
		else{
			_life = _life - theDamage;
		}
	}
/*----------CURE-------------*/
	void cure(const int & theCure)
	{
		if(_life==10){
			_life=_life;
		}
		else{
			_life = _life+ theCure;
		}
	}

};

//Character_hxx
#endif
