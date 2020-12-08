/******************************************************************************
* Cathy Strunk (Shands)
* Player.cpp
* CS 281-0798, Fall 2020
*
* Player class definition
*******************************************************************************
*/
#include <string>
#include <vector>

#include "Room.h"
#include "Player.h"
#include "Treasure.h"

//***********************************************************
// Player(string name)
//
// overload constructor 1 of 2
//***********************************************************
Player::Player(const std::string& name, int nLives)
{
    m_id = static_cast<int>('p');   // 'p' for player
    m_name = name;
    m_nLives = nLives;
}

//***********************************************************
// Player(string name)
//
// overload constructor 2 of 2
//***********************************************************
Player::Player(const std::string& name) : Player(name, PLAYER_LIVES)
{  }

//***********************************************************
// Player()
//
// constructor
//***********************************************************
Player::Player() : Player("player 1", PLAYER_LIVES) { }

//***********************************************************
// getLives()
//***********************************************************
int Player::getLives() const { return m_nLives; }

//***********************************************************
// setLives()
//***********************************************************
int Player::setLives(int n) { return m_nLives = n; }

//***********************************************************
// addLives()
//***********************************************************
int Player::addLives(int n) { return m_nLives += n; }

//***********************************************************
// loseLife()
//***********************************************************
int Player::loseLife() { return --m_nLives; }

//***********************************************************
// setId()
//
// must implement this member function because
// it's declared as pure virtual in base class CarryIt
//
// identify MagicWord class
//
// NOTE: member variable m_id is initialized to 
// 'MAGICWORD_DEFAULT_REVEAL' in constructor
//
// set m_id to passed value
//***********************************************************
bool Player::setId(int id)
{
    m_id = id;
    return true;
}

//***********************************************************
// addRoomVisit()
//
// adds Room pointer to Player's Room visit history
//***********************************************************
int Player::addRoomVisit(Room* pR)
{
    m_pRoomsVisitedV.push_back(pR);
    return m_pRoomsVisitedV.size();
}

//***********************************************************
// clearRoomVisits()
//
// clears Player's Room visit history
//***********************************************************
bool Player::clearRoomVisits()
{
    m_pRoomsVisitedV.clear();
    return true;
}

//***********************************************************
// getRoomVisits()
//
// returns the Player's number of Room visits
//***********************************************************
int Player::getRoomVisits(std::vector<Room*>& pRV)
{
    pRV.clear();
    for (Room* pR : m_pRoomsVisitedV)
    {
        pRV.push_back(pR);
    }
    return m_pRoomsVisitedV.size(); 
}

//***********************************************************
// addTreasure()
//
// adds a Treasure instance pointer to the container's
// vector of Treasure instance pointers
//
// returns the number of treasures in the vector
//***********************************************************
int Player::addTreasure(Treasure* pT)
{
    int n = Container::addTreasure(pT);

    // update Player points
    m_points += pT->getPoints();

    return n;
}

//***********************************************************
// removeTreasure()
//
// if the Treasure vector is not empty,
//  1) get the last Treasure in the vector
//  2) remove one Treasure from vector
//  3) take away Player Treasure points
//  4) return pointer to Treasure taken from Player or nullptr
//***********************************************************
Treasure* Player::removeTreasure()
{
    Treasure* pT = Container::removeTreasure();

    // update Player points
    if (pT != nullptr)
        m_points -= pT->getPoints();

    return pT;
}

//***********************************************************
// addWeapon()
//
// adds a Weapon instance pointer to the Player's
// vector of Weapon instance pointers
//
// returns the number of Weapons in the vector
//***********************************************************
int Player::addWeapon(Weapon* pW)
{
    int n = Container::addWeapon(pW);

    // update Player points
    m_points += pW->getPoints();

    return n;
}

//***********************************************************
// removeWeapon()
//
// if the Weapon vector is not empty,
//  1) get the last Weapon in the vector
//  2) remove one Weapon from vector
//  3) take away Player Weapon points
//  4) return pointer to Weapon taken from Player or nullptr
//***********************************************************
Weapon* Player::removeWeapon()
{
    Weapon* pW = Container::removeWeapon();

    // update Player points
    if (pW != nullptr)
        m_points -= pW->getPoints();

    return pW;
}

//***********************************************************
// addBogie()
//
// adds a Bogie instance pointer to the Player's
// vector of Bogie instance pointers
//
// returns the number of Bogies in the vector
//***********************************************************
int Player::addBogie(Bogie* pB)
{
    int n = Container::addBogie(pB);

    // update Player points
    m_points += pB->getPoints();

    return n;
}

//***********************************************************
// removeBogie()
//
// if the Bogie vector is not empty,
//  1) get the last Bogie in the vector
//  2) remove one Bogie from vector
//  3) take away Player Bogie points
//  4) return pointer to Bogie taken from Player or nullptr
//***********************************************************
Bogie* Player::removeBogie()
{
    Bogie* pB = Container::removeBogie();

    // update Player points
    if (pB != nullptr)
        m_points -= pB->getPoints();

    return pB;
}




