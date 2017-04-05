/*
 * EnumPowerupType.h
 * Enumerates the different types of Gridblast powerups
 * Created by Andrew Davis
 * Created on 3/31/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_PUP_TYPE
#define ENUM_PUP_TYPE

//enum definition
enum class EnumPowerupType {
	NONE, //used for deserialization
	SHLD, //shield (auto)
	MGNFY, //magnifying glass (manual)
	SKIP, //end level (manual)
	SMGNFY, //super magnifying glass (manual)
	BONUS, //bonus points (manual)
	SSHLD, //super shield (auto)
	MMGNFY, //mega magnifying glass (manual)
	MSHLD, //mega shield (auto)
};

#endif
