/*
 * functions.h
 * Defines inline functions that support Gridblast
 * Created by Andrew Davis
 * Created on 3/31/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef FUNC_H_INC
#define FUNC_H_INC

//includes
#include <SDL2/SDL.h>
#include <fstream>
#include <string>
#include "constants.h"
#include "../data/GameDB.h"

//first fileExistsAtPath function - returns whether or not a file exists at a path
inline bool fileExistsAtPath(const char* path) {
	std::ifstream ifs(path); //get a stream to check the path's validity
	return ifs.good(); //return whether the stream is good
}

//second fileExistsAtPath function - returns the same thing as the first
inline bool fileExistsAtPath(std::string path) {
	return fileExistsAtPath(path.c_str()); //call the other fileExistsAtPath function
}

//isNaN function - returns whether a character is not a number
inline bool isNaN(char test) {
	bool inv = (test >= '0' && test <= '9'); //get whether or not the character is a number
	return !inv; //and return the inverse of that calculation
}

//shutdownGame function - starts the shutdown process of the game
inline void shutdownGame() {
	GameDB::getInstance().setInt(OP_KEY, SHUTDOWN); //set the operation status field in the database to the shutdown value
}

//uwait function - delays the game a given number of milliseconds
inline void uwait(unsigned int time) {
	SDL_Delay(time); //delay the specified time
}

//wait function - delays the game a given number of seconds
inline void wait(int time) {
	uwait(time * 1000); //call the uwait function
}

#endif
