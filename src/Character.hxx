



#define Character_hxx

class Character{

//ATRIBUTS d'entrada

std::string _name;
int _level;

public:

//Constructor de la classe

	Character()
		//inicialització per defecte
		: _name("unknown")
		
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

	const int & level() const
	{
		return _level;
	}

};

 //Character_hxx

