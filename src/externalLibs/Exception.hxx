/*
*	PRACTICA 3 : Xavier Maltas i Oscar Crespo
*/

#ifndef EXCEPTION_HXX
#define EXCEPTION_HXX 

class Exception{

	public:
		Exception()
			//Variables inicial
			: _what("The item does not exist")
		
		{}

/*METODES*/

		std::string what()
		{
			return _what;
		}
#endif
