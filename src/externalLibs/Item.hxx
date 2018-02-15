/*
*	PRACTICA 2 : Xavier Maltas i Oscar Crespo
*/

#ifndef ITEM_HXX
#define ITEM_HXX 

class Item{

std::string _name;
int _level;
bool _enable;

	public:
		Item()
			//Variables inicials
			: _name("unknown"),
			_level(10u),
			_enable(false)
		
		{}

		//Metodes
/*----------NAME-------------*/
		//Getter name
		const std::string & name() const
		{
			return _name;
		}

		
		//Setter name
		void name(const std::string &name) 
		{
			_name = name;
		}
/*----------LEVEL-------------*/
		//getter level
		 const int & level()  const
		{
			return _level;
		}
		//setter level
		void level(const int & theLevel){
			_level = theLevel;
		}
/*----------ENABLE-------------*/
		//getter enable
		const bool & enable() const
		{
			return _enable;
		}
		//setter enable
		void enable( const bool & theEnable)
		{
			_enable = theEnable;
		}

};



#endif
