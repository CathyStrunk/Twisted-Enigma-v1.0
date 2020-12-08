/******************************************************************************
* Cathy Strunk (Shands)
* Container.cpp
* CS 281-0798, Fall 2020
*
* Container pure abstract class definition
*******************************************************************************
*/
#include <string>
#include <vector>

#include "Container.h"

//***********************************************************
// Container(string name)
//
// constructor
//***********************************************************
Container::Container()
{
    m_id = -1;
    m_name = "container";
    m_points = 0;               // accumulated points
}

//***********************************************************
// setId() declared as pure virtual
//***********************************************************

//***********************************************************
// getId()
//***********************************************************
int Container::getId() const
{
    return m_id;
}

//***********************************************************
// setName()
//
// copies passed string into member string 
//***********************************************************
bool Container::setName(std::string& name)
{
    m_name = name;
    return true;
}

//***********************************************************
// getName()
//
// copies member string into caller's string    
//***********************************************************
bool Container::getName(std::string& str) const
{
    str = m_name;
    return true;
}

//***********************************************************
// addPoints()
//
// adds passed value to container's points
//***********************************************************
int Container::addPoints(int points) 
{
    m_points += points;
    return true;
}

//***********************************************************
// setPoints()
//
// sets container's points to passed value
//***********************************************************
bool Container::setPoints(int points)
{
    m_points = points;
    return true;
}

//***********************************************************
// getPoints()
//
// returns how many points the container has
//***********************************************************
int Container::getPoints() const { return m_points; }

//***********************************************************
// setRoomVisit()
//***********************************************************
bool Container::setRoomVisits()
{
    m_roomVisits += 1;
    return true;
}

//***********************************************************
// getRoomVisit()
//***********************************************************
int Container::getRoomVisits()
{
    return m_roomVisits;
}

//***********************************************************
// addTreasure()
//
// adds a Treasure instance pointer to the container's
// vector of Treasure instance pointers
//
// returns the number of treasures in the vector
//***********************************************************
int Container::addTreasure(Treasure* pT)
{
    m_pTreasureV.push_back(pT);
    return m_pTreasureV.size();
}

//***********************************************************
// removeTreasure()
//
// if the Treasure vector is not empty,
//  1) get the last Treasure in the vector
//  2) remove one Treasure from vector
//  3) return pointer to Treasure removed or nullptr
//***********************************************************
Treasure* Container::removeTreasure()
{
    if (m_pTreasureV.size() == 0)
        return nullptr;

    Treasure* pT = m_pTreasureV.back();
    // remove Treasure from vector
    m_pTreasureV.pop_back();

    return pT;
}

//***********************************************************
// selectTreasure()
//
// checks the treasure vector for a specific treasure
// by name
//
// returns pointer to the treasure if found
// returns nullptr if not found
//***********************************************************
Treasure* Container::selectTreasure(const std::string& tName)
{
    for (auto pT : m_pTreasureV)
    {
        std::string str;
        pT->getName(str);

        if (tName.compare(str))
            return pT;
    }

    return nullptr;
}

//***********************************************************
// getTreasureCount()
//
// return number of treasures in this Room
//***********************************************************
int Container::getTreasureCount() const
{
    return m_pTreasureV.size();
}

//***********************************************************
// getTreasureInfo()
//
// copy Treasure vector elements to passed vector
//
// return number of Treasure elements 
//***********************************************************
int Container::getTreasureInfo(std::vector<Treasure*>& tV) const
{
    if (m_pTreasureV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Treasure* t : m_pTreasureV)
    {
        tV.push_back(t);
    }

    return tV.size();
}

//***********************************************************
// removeAllTreasure()
//***********************************************************
bool Container::removeAllTreasure()
{
    m_pTreasureV.clear();
    return true;
}

//***********************************************************
// addWeapon()
//
// adds a Weapon instance pointer to the container's
// vector of Weapon instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Container::addWeapon(Weapon* pW)
{
    m_pWeaponV.push_back(pW);
    return m_pWeaponV.size();
}

//***********************************************************
// removeWeapon()
//
// if the Weapon vector is not empty,
//  1) get the last Weapon in the vector
//  2) remove one Weapon from vector
//  3) return pointer to Treasure removed or nullptr
//***********************************************************
Weapon* Container::removeWeapon()
{
    if (m_pWeaponV.size() == 0)
        return nullptr;

    Weapon* pW = m_pWeaponV.back();
    // remove Treasure from vector
    m_pWeaponV.pop_back();

    return pW;
}

//***********************************************************
// getWeaponCount()
//
// return number of weapons in this Room
//***********************************************************
int Container::getWeaponCount() const
{
    return m_pWeaponV.size();
}

//***********************************************************
// getWeaponInfo()
//
// copy Weapon vector elements to passed vector
//
// return number of Weapon elements 
//***********************************************************
int Container::getWeaponInfo(std::vector<Weapon*>& wV) const
{
    if (m_pWeaponV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Weapon* w : m_pWeaponV)
    {
        wV.push_back(w);
    }

    return wV.size();
}

//***********************************************************
// selectWeapon()
//
// checks the weapon vector for a specific weapon
// by name
//
// returns pointer to the weapon if found
// returns nullptr if weapon not found
//***********************************************************
Weapon* Container::selectWeapon(const std::string& wName)
{

    for (auto pW : m_pWeaponV)
    {
        std::string str;
        pW->getName(str);
        int x = wName.compare(str);
        if (x == 0)
            return pW;
        else
            return nullptr;
    }
}

//***********************************************************
// removeAllWeapon()
//***********************************************************
bool Container::removeAllWeapon()
{
    m_pWeaponV.clear();
    return true;
}

//***********************************************************
// addBogie()
// 
// Adds a bogie pointer instance to the container's
// vector of bogie instance pointers
//
// returns the number of bogies in the  pointers
//***********************************************************
int Container::addBogie(Bogie* pB)
{
    m_pBogieV.push_back(pB);
    return m_pBogieV.size();
}

//***********************************************************
// removeBogie()
//
// if the Bogie vector is not empty,
//  1) get the last Bogie in the vector
//  2) remove one Bogie from vector
//  3) return pointer to Bogie removed or nullptr
//***********************************************************
Bogie* Container::removeBogie()
{
    if (m_pBogieV.size() == 0)
        return nullptr;

    Bogie* pB = m_pBogieV.back();

    // remove Bogie from vector
    m_pBogieV.pop_back();

    return pB;
}

//***********************************************************
// selectBogie()
//
// checks the Bogie vector for a specific Bogie
// by name
//
// returns pointer to the Bogie if found
// returns nullptr if not found
//***********************************************************
Bogie* Container::selectBogie(const std::string& bName)
{
    for (auto pB : m_pBogieV)
    {
        std::string str;
        pB->getName(str);

        if (bName.compare(str))
            return pB;
    }

    return nullptr;
}

//***********************************************************
// getBogieCount()
//
// return number of bogies in this Room
//***********************************************************
int Container::getBogieCount() const
{
    return m_pBogieV.size();
}

//***********************************************************
// getBogieInfo()
//
// copy Bogie vector elements to passed vector
//
// return number of Bogie elements 
//***********************************************************
int Container::getBogieInfo(std::vector<Bogie*>& bV) const
{
    if (m_pBogieV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (Bogie* b : m_pBogieV)
    {
        bV.push_back(b);
    }

    return bV.size();
}

//***********************************************************
// removeAllBogie()
//***********************************************************
bool Container::removeAllBogie()
{
    m_pBogieV.clear();
    return true;
}

//***********************************************************
// addMagicWord()
// 
// Adds a magic word pointer instance to the container's
// vector of magic word instance pointers
//
// returns the number of magic words in the vector
//***********************************************************
int Container::addMagicWord(MagicWord* pMW)
{
    m_pMagicWordV.push_back(pMW);
    return m_pMagicWordV.size();
}

//***********************************************************
// removeMagicWord()
//
// if the MagicWord vector is not empty,
//  1) get the last MagicWord in the vector
//  2) remove one MagicWord from vector
//  3) return pointer to MagicWord removed or nullptr
//***********************************************************
MagicWord* Container::removeMagicWord()
{
    if (m_pMagicWordV.size() == 0)
        return nullptr;

    MagicWord* pMW = m_pMagicWordV.back();

    // remove MagicWord from vector
    m_pMagicWordV.pop_back();

    return pMW;
}

//***********************************************************
// selectMagicWord()
//
// checks the MagicWord vector for a specific word
// by name
//
// returns pointer to the magicword if found
// returns nullptr if not found
//***********************************************************
MagicWord* Container::selectMagicWord(const std::string& mwName)
{
    for (auto pMW : m_pMagicWordV)
    {
        std::string str;
        pMW->getName(str);

        if (mwName.compare(str))
            return pMW;
    }

    return nullptr;
}

//***********************************************************
// getMagicWordCount()
//
// return number of magic words in this Room
//***********************************************************
int Container::getMagicWordCount() const
{
    return m_pMagicWordV.size();
}

//***********************************************************
// getMagicWordInfo()
//
// copy Magic Word vector elements to passed vector
//
// return number of magic word elements 
//***********************************************************
int Container::getMagicWordInfo(std::vector < MagicWord*>& mwV) const
{
    if (m_pMagicWordV.size() == 0)
        return 0;

    // copy values - prevent direct access to Container's vector
    for (MagicWord* m : m_pMagicWordV)
    {
        mwV.push_back(m);
    }

    return mwV.size();
}

//***********************************************************
// removeAllMagicWord()
//***********************************************************
bool Container::removeAllMagicWord()
{
    m_pMagicWordV.clear();
    return true;
}




