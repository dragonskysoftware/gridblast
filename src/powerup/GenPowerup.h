/*
 * GenPowerup.h
 * Declares a class that represents a generalized powerup for Gridblast
 * Created by Andrew Davis
 * Created on 3/31/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef GEN_PUP_H_INC
#define GEN_PUP_H_INC

//includes
#include <iostream>
#include <string>
#include <climits>
#include "EnumPowerupClass.h"
#include "EnumPowerupType.h"
#include "../data/GameDB.h"
#include "../util/constants.h"
#include "../except/InvalidPowerupException.h"

//class declaration
class GenPowerup {
	//public fields and methods
	public:
		//default constructor
		GenPowerup();

		//constructor
		GenPowerup(const std::string& newName, EnumPowerupType newPType, EnumPowerupClass newPClass);

		//destructor
		virtual ~GenPowerup();

		//copy constructor
		GenPowerup(const GenPowerup& gp);

		//move constructor
		GenPowerup(GenPowerup&& gp);

		//assignment operator
		GenPowerup& operator=(const GenPowerup& src);

		//move operator
		GenPowerup& operator=(GenPowerup&& src);

		//getter methods
		unsigned long long getID() const; //returns the unique ID of the powerup
		const std::string& getName() const; //returns the name of the powerup
		EnumPowerupType getType() const; //returns the type of powerup this is
		EnumPowerupClass getClass() const; //returns the class of powerup this is

		//serialization functions
		friend std::ostream& operator<<(std::ostream& os, const GenPowerup& gp); //save function
		friend std::istream& operator>>(std::istream& is, GenPowerup& gp); //load function

		//abstract method
		virtual void activatePowerup() const = 0; //activates the powerup

	//protected fields and methods
	protected:
		static unsigned long long s_id; //used to create unique IDs
		unsigned long long id; //the unique ID of the powerup
		std::string name; //the name of the powerup
		EnumPowerupType p_type; //the type of the powerup
		EnumPowerupClass p_class; //the class of the powerup

};

#endif
