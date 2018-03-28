#ifndef CHARACTER_HXX
#define CHARACTER_HXX 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Location;

class Character{

	protected:
	std::string _name;
	unsigned int _level;
	unsigned int _life;
	unsigned int _damage;
	unsigned int _cure;
	Location * _location;

	public:
		Character()
			:_name("unknown"), 
			 _level(0u), 	   
			 _life(10u),       
			 _location(0)
		{}

/*-----------------------NAME------------------------*/		 

		const std::string & name() const{
			return _name;
		}//name

		void name(const std::string &name){
			_name = name;
		}//name
/*-----------------------LEVEL------------------------*/	
		const unsigned int & level() const{
			return _level;
		}//level
		
		
		void level(const unsigned int &level){
			_level = level;
		}//level

/*-----------------------DAMAGE------------------------*/	
		std::string damage(const unsigned int &damage){
			if(_life < damage ){
				_life = 0;
			}
			else{
				_life = _life-damage;
			}

			std::stringstream output;
			output << damage;

			return " takes " + output.str() + " damage\n";

		}//damae
		
/*-----------------------LIFE------------------------*/	

		void life(const unsigned int &life){
			_life = life;
		}//life

		const unsigned int & life(){
			return _life;
		}//lifE

/*-----------------------CURE------------------------*/	
		std::string cure(const unsigned int &cure){
			if(_life==10){
			_life=_life;
			}
			else{
			_life = _life+cure;
			}

			std::stringstream output;
			output << cure;

			return " gains " + output.str() + " life\n";
		}//cure

		void locateAt( Location & newLocation );
		
		
		virtual std::string receiveMagic(const unsigned int points){
			std::stringstream output;
			output << name() << " receives " << points <<" magic points\n";
			return output.str(); 
			
		}//reciveMagic

		virtual ~Character() {}

		Location* currentLocation(){
			return _location;
		}
		
		void currentLocation( Location* newLocation ){
			_location = newLocation;
		}

};
 

#endif
