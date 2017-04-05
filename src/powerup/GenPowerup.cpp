/*
 * GenPowerup.cpp
 * Implements a class that represents a generalized powerup for Gridblast
 * Created by Andrew Davis
 * Created on 4/5/2017
 * Open source (GPL license)
 */

//include header
#include "GenPowerup.h"

//init static field
unsigned long long GenPowerup::s_id = 0; //initialize the static ID field

//default constructor
GenPowerup::GenPowerup()
	: id(s_id++), name(), p_type(EnumPowerupType::NONE), p_class(EnumPowerupClass::NONE) //init the fields with empty values
{
	if(s_id == ULLONG_MAX) { //if the maximum ID value has been reached
		s_id = 0; //then set the ID maker to 0
	}
}

//main constructor
GenPowerup::GenPowerup(const std::string& newName, EnumPowerupType newPType, EnumPowerupClass newPClass)
	: id(s_id++), name(newName), p_type(newPType), p_class(newPClass) //init the fields
{
	if(s_id == ULLONG_MAX) { //if the maximum ID value has been reached
		s_id = 0; //then set the ID maker to 0
	}
}

//destructor
GenPowerup::~GenPowerup() {
	//no code needed
}

//copy constructor
GenPowerup::GenPowerup(const GenPowerup& gp)
	: id(s_id++), name(gp.name), p_type(gp.p_type), p_class(gp.p_class) //copy the fields
{
	if(s_id == ULLONG_MAX) { //if the maximum ID value has been reached
		s_id = 0; //then set the ID maker to 0
	}

}

//move constructor
GenPowerup::GenPowerup(GenPowerup&& gp)
	: id(s_id++), name(gp.name), p_type(gp.p_type), p_class(gp.p_class) //move the fields
{
	if(s_id == ULLONG_MAX) { //if the maximum ID value has been reached
		s_id = 0; //then set the ID maker to 0
	}

}

//assignment operator
GenPowerup& GenPowerup::operator=(const GenPowerup& src) {
	this->name = src.name; //assign the name field
	this->p_type = src.p_type; //assign the powerup type field
	this->p_class = src.p_class; //assign the powerup class field
	return *this; //return the object
}

//move operator
GenPowerup& GenPowerup::operator=(GenPowerup&& src) {
	this->name = src.name; //move the name field
	this->p_type = src.p_type; //move the powerup type field
	this->p_class = src.p_class; //move the powerup class field
	return *this; //return the object
}

//getter methods

//getID method - returns the unique ID of the powerup
unsigned long long GenPowerup::getID() const {
	return this->id; //return the ID field
}

//getName method - returns the name of the powerup
const std::string& GenPowerup::getName() const {
	return this->name; //return the name field
}

//getType method - returns the type of the powerup
EnumPowerupType GenPowerup::getType() const {
	return this->p_type; //return the type field
}

//getClass method - returns the class of the powerup
EnumPowerupClass GenPowerup::getClass() const {
	return this->p_class; //return the class field
}

//serialization functions

//save function - writes the powerup to a stream
std::ostream& operator<<(std::ostream& os, const GenPowerup& gp) {
	os << gp.name; //serialize the name
	os << static_cast<int>(gp.p_type); //serialize the powerup type
	os << static_cast<int>(gp.p_class); //serialize the powerup class
	return os; //and return the stream
}

//load function - loads the powerup from a stream
std::istream& operator>>(std::istream& is, GenPowerup& gp) {
	is >> gp.name; //deserialize the name
	int rawType = 0; //used to deserialize the powerup type
	int rawClass = 0; //used to deserialize the powerup class
	is >> rawType; //deserialize the type
	gp.p_type = static_cast<EnumPowerupType>(rawType); //and assign it to the powerup type field
	is >> rawClass; //deserialize the class
	gp.p_class = static_cast<EnumPowerupClass>(rawClass); //and assign it to the powerup class field
	return is; //and return the stream
}

//other method is abstract

//end of implementation
