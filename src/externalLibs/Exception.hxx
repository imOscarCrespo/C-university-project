/*
*	PRACTICA 3 : Xavier Maltas i Oscar Crespo
*/

#ifndef EXCEPTION_HXX
#define EXCEPTION_HXX
//#include <iostream>
//#include <exception>
using namespace std; 

class Exception : public exception{

	public:
		const char * what() const throw(){
			return "The item does not exist";
		}
};
#endif