/*
 * InvalidDictEntryException.h
 * Declares an exception that is thrown when an invalid dictionary entry is found
 * Created by Andrew Davis
 * Created on 3/31/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef INVAL_DICT_EXCE
#define INVAL_DICT_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidDictEntryException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidDictEntryException(const char* badEntry);

		//destructor
		~InvalidDictEntryException();

		//copy constructor
		InvalidDictEntryException(const InvalidDictEntryException& idee);

		//move constructor
		InvalidDictEntryException(InvalidDictEntryException&& idee);

		//assignment operator
		InvalidDictEntryException& operator=(const InvalidDictEntryException& src);

		//move operator
		InvalidDictEntryException& operator=(InvalidDictEntryException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
