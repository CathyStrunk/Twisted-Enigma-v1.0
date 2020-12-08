/******************************************************************************
* Cathy Strunk (Shands)
* Treasure.cpp
* CS 281-0798, Fall 2020
*
* Treasure class definition
*******************************************************************************
*/
#include <string>

#include "CarryIt.h"
#include "Treasure.h"

//***********************************************************
// Treasure(string tName)
//
// overload constructor
//
// tName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Treasure::Treasure(std::string tName)
{
    m_id = static_cast<int>('t');   // 't' means Treasure
    m_name = tName;
}

//***********************************************************
// Treasure()
//
// constructor
//***********************************************************
Treasure::Treasure() : Treasure("untold treasure") { }

//***********************************************************
// setRevealWord()
//
// to Reveal hidden treasure with MagicWord
//***********************************************************
bool Treasure::setRevealWord(const std::string& rWord)
{
    m_RevealWord = rWord;
    return true;
}

//***********************************************************
// getRevealWord()
//
// gets Reveal word to reveal hidden treasure with MagicWord
//***********************************************************
std::string& Treasure::getRevealWord(std::string& rWord) const
{
    return (rWord = m_RevealWord);
}

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in the base class
//
// identify Treasure class or unique Treasure
//
// NOTE: member variable m_id is initialized to (int) 't'
// in Treasure constructor
//
// set m_id to passed value
//***********************************************************
bool Treasure::setId(int id)
{ 
    m_id = id;
    return true;
}


