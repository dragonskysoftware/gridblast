/*
 * InvalidPowerupException.cpp
 * Implements an exception that is thrown when an invalid powerup is found
 * Created by Andrew Davis
 * Created on 4/5/2017
 * Open source (GPL license)
 */

//include header
#include "InvalidPowerupException.h"

//constructor
InvalidPowerupException::InvalidPowerupException(const char* msg)
	: errorString(msg) //init the error message string
{
	this->errorString = "InvalidPowerupException thrown! Message: " + this->errorString; //append a prefix to the error string
}

//destructor
InvalidPowerupException::~InvalidPowerupException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidPowerupException::InvalidPowerupException(const InvalidPowerupException& ipe)
	: errorString(ipe.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidPowerupException::InvalidPowerupException(InvalidPowerupException&& ipe)
	: errorString(ipe.errorString) //move the error string
{
	ipe.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidPowerupException& InvalidPowerupException::operator=(const InvalidPowerupException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidPowerupException& InvalidPowerupException::operator=(InvalidPowerupException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidPowerupException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


