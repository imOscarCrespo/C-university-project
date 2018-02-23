/*
*	PRACTICA 3 : Xavier Maltas i Oscar Crespo
*/

#ifndef EXCEPTION_HXX
#define EXCEPTION_HXX 

class Exception : public exeption{

	public:
		const char *what() const throw(){
			return "The item does not exist";
		}
};
#endif
