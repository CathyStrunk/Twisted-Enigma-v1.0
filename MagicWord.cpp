/******************************************************************************
* Cathy Strunk (Shands)
* MagicWord.cpp
* CS 281-0798, Fall 2020
*
* MagicWord class definition
*******************************************************************************
*/

#include <string>

#include "MagicWord.h"

//***********************************************************
// MagicWord(string mwName)
//
// overload constructor
//
// mwName is a call by value string parameter
// to allow passing string literals
//***********************************************************
MagicWord::MagicWord(std::string mwName)
{
	m_id = static_cast<int>('r');   // 'r' for Reveal;
	m_name = mwName;
}

//***********************************************************
// MagicWord()
//
// constructor
//***********************************************************
MagicWord::MagicWord() : MagicWord("A useful tool in the quest")
{ }

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in base class CarryIt
//
// identify MagicWord class
//
// NOTE: member variable m_id is initialized to 
// the reveal as the default
//
// set m_id to passed value
//***********************************************************
bool MagicWord::setId(int id)
{
	m_id = id;
	return true;
}

//***********************************************************
// getId()
//
// returns use ID of the magicword
//***********************************************************
int MagicWord::getId()
{
	return m_id;
}