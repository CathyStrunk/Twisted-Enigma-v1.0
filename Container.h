/******************************************************************************
* Cathy Strunk (Shands)
* Container.h
* CS 281-0798, Fall 2020
*
* Container pure abstract class declaration
*******************************************************************************
*/
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

#include "CarryIt.h"
#include "Treasure.h"
#include "Weapon.h"
#include "Bogie.h"
#include "MagicWord.h"

class Container
{
protected:
    int m_id;                              // internal use
    std::string m_name;                    // user supplied name
    int m_points;                          // accumulated points
    int m_roomVisits;                      // roomVisit tracker
    std::vector<Treasure*> m_pTreasureV;   // accumulated Treasure
    std::vector<Weapon*> m_pWeaponV;       // accumulated Weapons
    std::vector<Bogie*> m_pBogieV;         // accumulated Bogies
    std::vector<MagicWord*> m_pMagicWordV; // accumulated MagicWords

    // mixed type carryable items vector for optional use
    std::vector<CarryIt*> m_pCarryItV;

public:
    Container();
    // Container instances will persist for app lifetime
    // so destructor not needed
    //~Container();

    // derived classes must implement this member function
    virtual bool setId(int id) = 0;

    int getId() const;

    bool setName(std::string& name);
    bool getName(std::string& str) const;

    int addPoints(int points);
    bool setPoints(int points);
    int getPoints() const;

    bool setRoomVisits();
    int getRoomVisits();

    // Treasure management support
    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();
    Treasure* selectTreasure(const std::string& tName);
    int getTreasureCount() const;
    int getTreasureInfo(std::vector<Treasure*>& pTV) const;
    bool removeAllTreasure();

    // Weapon management support
    int addWeapon(Weapon* pT);
    Weapon* removeWeapon();
    Weapon* selectWeapon(const std::string& wName);
    int getWeaponCount() const;
    int getWeaponInfo(std::vector<Weapon*>& pWV) const;
    bool removeAllWeapon();

    // Bogie management support
    int addBogie(Bogie* pT);
    Bogie* removeBogie();
    Bogie* selectBogie(const std::string& bName);
    int getBogieCount() const;
    int getBogieInfo(std::vector<Bogie*>& pBV) const;
    bool removeAllBogie();

    // MagicWord management support
    int addMagicWord(MagicWord* pMW);
    MagicWord* removeMagicWord();
    MagicWord* selectMagicWord(const std::string& mwName);
    int getMagicWordCount() const;
    int getMagicWordInfo(std::vector < MagicWord*>& pMWV) const;
    bool removeAllMagicWord();

};

#endif
