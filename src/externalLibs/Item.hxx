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
		std::string name()
		{
			return "";
		}

		/*//Setter name
		void name(const std::string &name) 
		{
			_name = name;
		}

		//getter
		 const int & level()  const
		{
			return _level;
		}
		//setter
		void level(const int & theLevel){
			_level = theLevel;
		}


		//getter
		const bool & enable() const
		{
			return _enable;
		}
		//setter
		void enable( const bool & theEnable)
		{
			_enable = theEnable;
		}*/

};



#endif
