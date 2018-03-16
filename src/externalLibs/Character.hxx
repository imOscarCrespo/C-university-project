/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

#ifndef CHARACTER_HXX
#define CHARACTER_HXX

#include <iostream>
// #include <string>
// #include <list>
// #include <algorithm>
#include <vector>
// #include <exception>

class Location;

class Character{

	std::string _name;
	int _level;
	int _life;
	int _damage;
	int _cure;
	Location * _location;

	public:

		//Constructor de la classe

			Character()
				//inicialització per defecte
				:	_name("unknown"), 
					_level(0u), 
					_life(10u),
					_location(0)
			{}

			//Destructor
			~Character()
			{}

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
				const int & level()  const{
					return _level;
				}//level
			//setter
				void level(const int & theLevel){
					_level = theLevel;
				}//level
		/*----------LIFE-------------*/
			const int & life()  const{
				return _life;
			}//life

			void life(const int & theLife){
				_life = theLife;
			}//life
		/*----------DAMAGE-------------*/
			void damage(const int & theDamage){
				if(_life < theDamage){
					_life = 0;
				}
				else{
					_life = _life - theDamage;
				}
			}//damage
		/*----------CURE-------------*/
			void cure(const int & theCure){
				if(_life==10){
					_life=_life;
				}
				else{
					_life = _life + theCure;
				}
			}//cure
			
		//forwardDeclaration
		void locateAt( Location & location);

		std::string receiveMagic (int magicPoint){
			return this->name() + " receives " + std::to_string(magicPoint) + "magic points\n";
		}

};

//Character_hxx
#endif
