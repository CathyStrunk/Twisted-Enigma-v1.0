/******************************************************************************
* Cathy Strunk (Shands)
* MagicWord.h
* CS 281 - 0798, Fall 2020
*
* MagicWord class declaration
*******************************************************************************
*/
#ifndef MAGICWORD_H
#define MAGICWORD_H

#include <string>

// base class declaration
#include "CarryIt.h"

//----------------------------------------------------------
// MagicWord class derived from base class for carried items
//----------------------------------------------------------
class MagicWord : public CarryIt
{
public:
	MagicWord();
	MagicWord(std::string mwName);
	//~MagicWord();

	// must implement pure virtual base class member function?
	bool setId(int id);
	int getId();
};

#endif
