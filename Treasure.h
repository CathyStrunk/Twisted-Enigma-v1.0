/******************************************************************************
* Cathy Strunk (Shands)
* Treasure.h
* CS 281-0798, Fall 2020
*
* Treasure class declaration
*******************************************************************************
*/
#ifndef TREASURE_H
#define TREASURE_H

#include <string>

// base class declaration
#include "CarryIt.h"

//----------------------------------------------------------
// Treasure class derived from base class for carried items
//----------------------------------------------------------
class Treasure : public CarryIt
{
private:
    std::string m_RevealWord;

public:
    Treasure();
    Treasure(std::string tName);
    // Treasure persists for app lifetime
    // so destructor not needed
    //~Treasure();

    bool setRevealWord(const std::string& rWord);
    std::string& getRevealWord(std::string& rWord) const;

    // must implement pure virtual base class member function
    bool setId(int id);
};

#endif
