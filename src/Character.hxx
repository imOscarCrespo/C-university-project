<<<<<<< HEAD
#ifndef Character hxx
#define Character_hxx

class Character{
	
	public: 

		std::string name()

		{
				return "hgj";
		}
};
#endif //Character_hxx
=======
#ifndef Character_hxx
#define Character_hxx

class Character{

//ATRIBUTS d'entrada

std::string _name;

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


};

#endif //Character_hxx
>>>>>>> 0782c9637f3441adcf5ed49dfc19460700a70d85
