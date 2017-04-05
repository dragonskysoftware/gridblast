/*
 * EnumPowerupClass.h
 * Enumerates the different classes of Gridblast powerups (manual and autouse)
 * Created by Andrew Davis
 * Created on 3/31/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_PUP_CLASS
#define ENUM_PUP_CLASS

//enum definition
enum class EnumPowerupClass {
	NONE, //used for deserialization
	MAN, //manual
	AUTO //autouse
};

#endif
