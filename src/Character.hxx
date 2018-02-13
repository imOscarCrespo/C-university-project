



#define Character_hxx

class Character{

//ATRIBUTS d'entrada

std::string _name;
int _level;
int _life;


public:

//Constructor de la classe

	Character()
		//inicialització per defecte
		: _name("unknown"), _level(0u), _life(10u)
		
		
	{

		 
	}


//Functions of the class

	//getter
	const std::string & name() const //utilitzem & com a punter i cap persona des d'una altra part del codi no pot canviar aquest valor que guardem a _name, per tant ha de ser constant.
	{
		return _name;
	}

	//setter
	void name(const std::string & theName){
		_name = theName;
	}

	 const int & level()  const
	{
		return _level;
	}

	void level(const int & theLevel){
		_level = theLevel;
	}

	const int & life()  const
	{
		return _life;

	}

	void life(const int & theLife){
		_life=theLife;
	}

	void damage(const int & theDamage){
		_life = _life - theDamage;


	}

	void cure(const int & theCure){
		_life = _life + theCure;


	}

	/*void mort(const int & theDamage){
		int i = _life.damage(theDamage);
		if(i<0){
			//Mates el pesonatje
		}
	}

	*/

	void maxcure(const int & theCure){
		this->cure(theCure);
		int x;
		x = this->life();

		if (x>=10u){
			_life = 10u;
		}
	}
};

 //Character_hxx

