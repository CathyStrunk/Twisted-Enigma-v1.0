/******************************************************************************
* Cathy Strunk (Shands)
* app_player.cpp
* CS 281 - 0798, Fall 2020
*
* Player initialization and management functions
*******************************************************************************
*/
#include <sstream>
#include <vector>

#include "app.h"



/******************************************************************************
* grabTreasure()
*
* transfer Treasure from Room to Player
* fill caller's vector with messages for display
*******************************************************************************
*/
bool grabTreasure(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ)
{
    Treasure* pTreasure = pRoom->removeTreasure();

    if (pTreasure == nullptr)
    {
        msgQ.push_back("There's no treasure here.\n");
        return false;
    }

    if (pTreasure->getHidden() == true)
    {
        grabTreasure(pPlayer, pRoom, msgQ);
        pRoom->addTreasure(pTreasure);
        return false;
    }

    pPlayer->addTreasure(pTreasure);
    std::string str;
    pTreasure->getName(str);

    // build message string with string stream
    std::stringstream ss;
    ss << "You have a " << str << " worth "
        << pTreasure->getPoints() << " points.\n";

    // add completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* dropTreasure()
*
* transfer Treasure from Player to Room
* fill caller's vector with message strings for display
*******************************************************************************
*/
bool dropTreasure(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ)
{
    Treasure* pTreasure = pPlayer->removeTreasure();

    if (pTreasure == nullptr)
    {
        msgQ.push_back("Your pockets are empty!\n");
        return false;
    }

    // transfer Treasure from Player to Room
    pRoom->addTreasure(pTreasure);

    // for queueing display message
    std::string str;
    pTreasure->getName(str);

    msgQ.push_back("You dropped a " + str + "!\n");

    return true;
}

/******************************************************************************
* grabWeapon()
*
* transfer Weapon from Room to Player
* add messages to caller's vector for display
*******************************************************************************
*/
bool grabWeapon(Player* pPlayer, Room* pRoom, std::vector<std::string>& msgQ)
{
    Weapon* pWeapon = pRoom->removeWeapon();

    if (pWeapon == nullptr)
    {
        msgQ.push_back("There's no weapon here.\n");
        return false;
    }

    pPlayer->addWeapon(pWeapon);
    std::string str;
    pWeapon->getName(str);

    // build message string with string stream
    std::stringstream ss;
    ss << "You have a " << str << " worth "
        << pWeapon->getPoints() << " points.\n";

    // copy completed message string to caller's vector
    msgQ.push_back(ss.str());

    return true;
}

/******************************************************************************
* fightBogie()
*
* transfer bogie from Room to Player
* add messages to caller's vector for display
*******************************************************************************
*/
bool fightBogie(Player* pPlayer, Room* pRoom, char firstLet, std::vector<std::string>& msgQ)
{
    int nBogie = pRoom->getBogieCount();

    if (nBogie > 0)
    {
        Bogie* pBogie = pRoom->removeBogie();
        std::string str, bName;
        char bKillW = pBogie->getKillWeapon();
        if (firstLet != bKillW)
        {
            str = "Weapon useless against this Boglaman!";
            msgQ.push_back(str);
            pPlayer->loseLife();
            str = "You lost a life.\n";
            msgQ.push_back(str);
            pRoom->addBogie(pBogie);
            return false;
        }
        pBogie->getDeathText(str);
        pBogie->getName(bName);
        if (bName.compare("Dragon") == 0)
        {
            Treasure* pT = pRoom->removeTreasure();
            pT->setHidden(false);
            pRoom->addTreasure(pT);
        }
        msgQ.push_back(str);
        pPlayer->addBogie(pBogie);
        return true;
    }
    
    return false;

}

/******************************************************************************
* interact()
*
* use a Weapon on a Bogey
* add messages to caller's vector for display
*******************************************************************************
*/
bool interact(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // Check for bogies present
    if (pR->getBogieCount() == 0)
    {
        msgQ.push_back("No Boglamen here...\n");
        return false;
    }
    // check for Weapon in Player vector
    if (pP->getWeaponCount() == 0 && pP->getMagicWordCount() == 0)
    {
        msgQ.push_back("You don't have any weapons.");
        pP->loseLife();
        msgQ.push_back("You lost a life!\n");
        return true;
    }
}

/******************************************************************************
* lookAllDirections()
*
* add all direction text in current Room to caller's message vector
*******************************************************************************
*/
bool lookAllDirections(Room* pRoom, std::vector<std::string>& msgQ)
{
    // utility buffer gets stomped every time through loop
    std::string str;

    // add text for all directions to caller's vector
    for (int i = 0; i < ROOM_NDIR; i++)
    {
        pRoom->getDirectionText(i, str);

        // only display text for diretions we're using 
        if (str != "")
            msgQ.push_back(str);
    }

    // display things in Room
    getInventory(pRoom, msgQ);

    return true;
}

/******************************************************************************
* movePlayer()
*
* look up pointer to next Room in given direction
* if there's a Room in that direction,
* display exit text in current Room
*
* return pointer to the new Room,
* or pointer to same Room if no Room in that direction
*
*******************************************************************************
*/
Room* movePlayer(Player* pP, Room* pR, int direction, std::vector<std::string>& msgQ)
{
    std::string str = "Dead end.";

    Room* pNextRoom = pR->getDirectionPtr(direction);
    if (pNextRoom != nullptr && pR->getBogieCount() == 0)
    {
        // "you are leaving" current Room
        pR->getExitText(str);
        pR->setRoomVisits();
        visitRoom(pP, pNextRoom, msgQ);

        return pNextRoom;
    }
    if (pNextRoom != nullptr && pR->getBogieCount() > 0)
    {
        // can't leave this room until bogie is dead
        Bogie* pB = pR->removeBogie();
        pB->getName(str);

        // build message string with string stream
        std::stringstream ss;
        ss << "The " << str << " is blocking your way.\n";

        // copy completed message string to caller's vector
        msgQ.push_back(ss.str());

        pR->addBogie(pB);

        return pR;
    }
    else
    {
        //nowhere to go in this direction, stay in current Room               
        pR->getDirectionText(direction, str);
        msgQ.push_back(str);
        
    } 

    return pR;
    
}

/******************************************************************************
* visitRoom()
*
* award Room points to Player
* update Player's Rooms visited history
* queue messages for display
*******************************************************************************
*/
bool visitRoom(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    // award Room points to Player
    int points = pR->getPoints();
    pP->addPoints(points);

    // update Player Room visit history
    pP->addRoomVisit(pR);
    
    pR->setRoomVisits();

    // build greeting messages and queue for display
    std::string str, roomName;
    pR->getName(roomName);

    msgQ.push_back("You're in the " + roomName + ".");

    pR->getEntryText(str);
    msgQ.push_back(str);

    // only award points for initial visit to each Room
    if (pR->getPoints() > 0)
    {
        std::stringstream ss;
        ss << points << " points for " << roomName << "!\n";

        msgQ.push_back(ss.str());
        pR->setPoints(0);
    }

    return true;
}

/******************************************************************************
* captureMagicWord()
*
* transfer MagicWord from Room to Player
* add messages to caller's vector for display
*******************************************************************************
*/
bool captureMagicWord(Player* pP, Room* pR, std::vector<std::string>& msgQ)
{
    MagicWord* pMW = pR->removeMagicWord();

    if (pMW == nullptr)
    {
        msgQ.push_back("There's no Magic here.\n");
        return false;
    }

    std::string str;
    pMW->getText(str);
    msgQ.push_back(str);
    pP->addMagicWord(pMW);
    
    return true;
}

/******************************************************************************
* doMagicWord()
*
* Player uses magic word
* queue messages for display
*******************************************************************************
*/
bool doMagicWord(Player* pP, Room* pR, char firstLet, std::vector <std::string>& msgQ)
{
    std::string str;            // message buffer

    // check for magic word in vector
    int nMagicWord = pP->getMagicWordCount();

    if (nMagicWord > 0)
    {
        // get magic word
        MagicWord* pMW = pP->removeMagicWord();
        std::string mwName;
        pMW->getName(mwName);
        char mwFLet = mwName.at(0);
        mwFLet = tolower(mwFLet);
        int mwID = pMW->getId();
        
        // get treasure and bogie counts
        int nTreasure = pR->getTreasureCount();
        int nBogie = pR->getBogieCount();
        
        // check for Magic Word usage (Reveal of Weapon)
        if ((mwID == (static_cast<int>('r'))) && (firstLet == mwFLet))
        {
            // check for treasure
            if (nTreasure > 0)
            {
                // get treasure so we can check if hidden
                Treasure* pT = pR->removeTreasure();

                // change hidden to reveal treasure it will now print
                if (pT->getHidden() == true && pR->getRoomVisits() > 1)
                {
                    pT->setHidden(false);

                    // add treasure back to the room
                    pR->addTreasure(pT);

                    // add magic word back to player vector
                    pP->addMagicWord(pMW);
                    return true;
                }
                else
                {
                    pR->addTreasure(pT);
                    pP->addMagicWord(pMW);
                    return false;
                }
                                    
                
            }
            else
            {
                msgQ.push_back("No treasure here!\n");
                pP->addMagicWord(pMW);
                return false;
            }
        }
        else if ((mwID == (static_cast<int>('w'))) && (firstLet == mwFLet))
        {
            if (nBogie > 0)
            {
                std::string wName;
                pMW->getName(wName);
                char wFLet = wName.at(0);
                wFLet = tolower(wFLet);
                fightBogie(pP, pR, wFLet, msgQ);
                pP->addMagicWord(pMW);
                return true;
            }

        }
    }

    msgQ.push_back("You don't have any magic!\n");
    return false;  

}


