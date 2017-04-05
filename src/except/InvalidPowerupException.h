/*
 * InvalidPowerupException.h
 * Declares an exception that is thrown when an invalid powerup is found
 * Created by Andrew Davis
 * Created on 4/5/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef INVAL_PUP_EXCE
#define INVAL_PUP_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidPowerupException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidPowerupException(const char* msg);

		//destructor
		~InvalidPowerupException();

		//copy constructor
		InvalidPowerupException(const InvalidPowerupException& ipe);

		//move constructor
		InvalidPowerupException(InvalidPowerupException&& ipe);

		//assignment operator
		InvalidPowerupException& operator=(const InvalidPowerupException& src);

		//move operator
		InvalidPowerupException& operator=(InvalidPowerupException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
