/******************************************************************************
* Cathy Strunk (Shands)
* Bogie.cpp
* CS 281-0798, Fall 2020
*
* Container pure abstract class definition
*******************************************************************************
*/
#include <string>

#include "Bogie.h"
#include "CarryIt.h"

//***********************************************************
// Bogie(string bName)
//
// overload constructor
//
// bName is a call by value string parameter
// to allow passing string literals
//***********************************************************
Bogie::Bogie(std::string bName)
{
    m_id = static_cast<int>('b');   // 'b' means Bogie
    m_name = bName;
    m_lifeStatus = true;
}

//***********************************************************
// Bogie()
//
// constructor
//***********************************************************
Bogie::Bogie() : Bogie("Boglamen appear!") { }

//***********************************************************
// setLifeStatus(int)
//
// sets the bogie's life status to 1 (alive) or 0 (dead)
// 
//***********************************************************
bool Bogie::setLifeStatus(int status)
{
	m_lifeStatus = status;
    if (m_lifeStatus == 1)
        return true;
    else
        return false;
    
}

//***********************************************************
// getLifeStatus()
//
// returns the bogie's current life status
//***********************************************************
bool Bogie::getLifeStatus()
{
	return m_lifeStatus;
}

//***********************************************************
// setDeathText()
//
// sets the text to display when Bogie dies
//***********************************************************
bool Bogie::setDeathText(const std::string& text)
{
    m_deathText = text;
    return true;
}

//***********************************************************
// getDeathText()
//
// returns the text to display when a bogie dies
//***********************************************************
std::string& Bogie::getDeathText(std::string& text) const
{
    return (text = m_deathText);
}

//***********************************************************
// setKillWeapon()
//
// sets the weapon the kills the bogie
//***********************************************************
bool Bogie::setKillWeapon(char kWInit)
{
    m_killWeapon = kWInit;
    return true;
}

//***********************************************************
// getKillWeapon()
//
// returns the kill weapon
//***********************************************************
char Bogie::getKillWeapon()
{
    return m_killWeapon;
}

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in the base class
//
// identify Bogie class or unique Bogie
//
// NOTE: member variable m_id is initialized to (int) 'b'
// in Bogie constructor
//
// set m_id to passed value
//***********************************************************
bool Bogie::setId(int id)
{
    m_id = id;
    return true;
}