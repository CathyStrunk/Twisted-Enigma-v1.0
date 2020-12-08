/******************************************************************************
* Cathy Strunk (Shands)
* app_init_rooms.cpp
* CS 281 - 0798, Fall 2020
*
* Room initialization functions
*   - set Room entry text, exit text, direction text
*   - install Treasures in Room Treasure vector or in Room mixed vector
*   - install Weapons in Room Weapon vector or in Room mixed vector
* #TODO
*   - install bogies in Room Bogie vector
*   - install magic words in Room MagicWord vector
*******************************************************************************
*/
#include "app.h"

/******************************************************************************
* Room* initWaterfrontPark()
*******************************************************************************
*/
Room* initWaterfrontPark()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Waterfront Park";
    pRoom->setName(str);

    str = "The world starts to shift and twist the longer you stare.\n";
    pRoom->setEntryText(str);

    str = "You are leaving the Waterfront Park.";
    pRoom->setExitText(str);

    str = "Looking north the whole of the town lies before you.\n"
        "The Mundane world starts to shift the longer you stare.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "To the south is the vast tidal marsh that surrounds the town.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Glancing east we can barely make out the shadowy figures\n"
        "of the large gothic homes bordering the tidal marsh.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "An oak tree lined street runs west.\n"
        "Graceful homes with sweeping porches peek from\n"
        "beneath the Spanish moss covered trees.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "A dark sky starts to roll in above you.\n"
        "The clouds clear as an inky blackness blankets the sky.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The cobble stones beneath your feet feel sturdy and real.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_NORTH, g_pTheCastle);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Copper chalice with silver filigree";
    pTreasure->setName(str);
    pTreasure->setPoints(50);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize second Treasure instance
    Treasure* pTreasure2 = new Treasure();
    str = "Ruby encrusted box";
    pTreasure2->setName(str);
    pTreasure2->setPoints(100);
    pTreasure2->setHidden(true);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure2);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Pirate sword";
    pWeapon->setName(str);
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    return pRoom;
}

/******************************************************************************
* Room* initTheCastle()
*******************************************************************************
*/
Room* initTheCastle()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(150);

    std::string str = "Castle";
    pRoom->setName(str);

    str = "The cold trapped in the stone walls chills the air around you.\n";
    pRoom->setEntryText(str);

    str = "You are leaving The Castle.";
    pRoom->setExitText(str);

    str = "As you squint through the windows you barely make out\n"
        "a vast stretch of land still smoldering from the Boglamen wars.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Peering out across the gardens you look south\n"
        "to the Waterfront Park. The black sky casting an eerie gloom\n"
        "over the town.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "Glancing east we watch the flickering lights of the oil lamps\n"
        "shimmering their way through from the Mundane world.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "To the west we see a set of stairs going down to a tunnel below.\n"
        "Where do you think it could lead?";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "The exposed rafters above haven't been dusted in years.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The marble tile is worn with age. Ivy grows across the floor\n"
        "mimicking the veins in the stone.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_SOUTH, g_pWaterfrontPark);
    pRoom->setDirectionPtr(ROOM_WEST, g_pArsenal);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Gold pocket watch";
    pTreasure->setName(str);
    pTreasure->setPoints(50);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Bedesci";
    pBogie->setName(str);
    str = "A flying dragonesque creatue that breathes ice.";
    pBogie->setText(str);
    pBogie->setPoints(100);
    pBogie->setDeathText("You puncture the ice pack of the Bedesci\n"
        "you watch as it slowly turns to ice. Your path is now clear.");
    pBogie->setKillWeapon('s'); 

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    // create and initalize Magic Word instance
    MagicWord* pMagicWord = new MagicWord();
    str = "MOBIATE";
    pMagicWord->setName(str);
    str = "The power to reveal has been bestowed upon you.\n";
    pMagicWord->setText(str);
    pMagicWord->setPoints(50);

    // install MagicWord point in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

/******************************************************************************
* Room* initArsenal()
*******************************************************************************
*/
Room* initArsenal()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Arsenal";
    pRoom->setName(str);

    str = "You pass through a massive stone door while\n"
        "the smell of gunpowder stings your nose.\n";
    pRoom->setEntryText(str);

    str = "Exiting the arsenal.";
    pRoom->setExitText(str);

    str = "Crates of weapons line the smooth stone wall before you.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Through the small slit in the door you can just make out the shadowy\n"
        "figures of the cemetary headstones. A pale mist blankets the air.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "The large stone door rumbles shut. You search but can't find\n"
        "a way to reopen it.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "More piles of crates in that direction.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "A low stone ceiling above.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "A rough stone floor smoothed by wear runs beneath your feet.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_SOUTH, g_pCemetary);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Silver pan flute";
    pWeapon->setName(str);
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Grauster";
    pBogie->setName(str);
    str = "A slithering, oozing creature that thrives off the scent\n"
        "of violence. They are often times used to guard arsenals,\n"
        "forts, or prisons.";
    pBogie->setText(str); 
    pBogie->setPoints(150);
    pBogie->setDeathText("The Grausters shrinks from the power of your magic.\n"
        "Hurry before they come back!");
    pBogie->setKillWeapon('r');

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    // create and initalize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    str = "REPELUS";
    pMagicWord->setName(str);
    str = "The power to repel has been bestowed upon you.\n";
    pMagicWord->setText(str);
    pMagicWord->setPoints(50);
    pMagicWord->setId(static_cast<int>('w'));   // 'w' for weapon

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

/******************************************************************************
* Room* initCemetary()
*******************************************************************************
*/
Room* initCemetary()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Cemetary";
    pRoom->setName(str);

    str = "You find yourself in a pale mist shrouded cemetary.\n";
    pRoom->setEntryText(str);

    str = "You hastily make your exit.";
    pRoom->setExitText(str);

    str = "To the North we can just make out the dark hulk of the Arsenal.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "Through the mist shapes swarm and dampened sounds come from\n"
        "the South. Fire shoots up into the sky between the yells.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "The bulk of the city lies to the East. You can just make out the\n"
        "shadows of buildings through thickening mist.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Pluff mud as far as the nose can smell.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "The massive oak trees overhead shroud the darkness in moss.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "You are standing on a grave. How rude!";
    pRoom->setDirectionText(ROOM_DOWN, str);

    pRoom->setDirectionPtr(ROOM_SOUTH, g_pDocks);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Carved jade dragon";
    pTreasure->setName(str);
    pTreasure->setPoints(100);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Weapon instance
    Weapon* pWeapon = new Weapon();
    str = "Silver dagger with emerald inlaid sheath";
    pWeapon->setName(str);
    pWeapon->setPoints(100);

    // install Weapon pointer in Room's Weapon vector
    pRoom->addWeapon(pWeapon);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Mistwraiths";
    pBogie->setName(str);
    str = "An ethereal being similar to a ghost and are often found in\n"
        "cemetaries. Their sweet melodious sounds confuses hearers and can\n"
        "drive them mad. Be careful as these creatures blend into the mist.";
    pBogie->setText(str);
    pBogie->setPoints(200);
    pBogie->setDeathText("The Mistwraiths are lulled by the sound of your\n"
        "flute. They slowly drift back off to their restful slumber.\n"
        "Don't stop playing now!");
    pBogie->setKillWeapon('f');

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);

    return pRoom;
}

/******************************************************************************
* Room* initDocks()
*******************************************************************************
*/
Room* initDocks()
{
    Room* pRoom = new Room();

    // set Room point value
    pRoom->setPoints(100);

    std::string str = "Docks";
    pRoom->setName(str);

    str = "Cold hugs you from all sides as the water laps against the rotting\n"
        "support posts. You can hear the splintering of the wood as the docks\n"
        "sway with the movement of the water.\n"
        "Before you appears a massive creature. A sweet sense of peace\n"
        "sweeps over you. As you follow the shadows towards the gray sky\n"
        "the image of a dragon appears. A small voice echoes in your head.\n"
        "\"Free me\" it says quietly.\n";
    pRoom->setEntryText(str);

    str = "Leaving the Docks";
    pRoom->setExitText(str);

    str = "Hurry! The Mistwraiths are waking.";
    pRoom->setDirectionText(ROOM_NORTH, str);

    str = "A large hulking figure appears at the end of the dock. You can\n"
        "hear metal clanging just beyond the mist.";
    pRoom->setDirectionText(ROOM_SOUTH, str);

    str = "The dark murky waters ripple and flash in the soft glow from the\n"
        "solitary lamp post.";
    pRoom->setDirectionText(ROOM_EAST, str);

    str = "Darkness stretches out before you. Lights from the houses of \n"
        "the Mundane world flicker in and out as the Magic realm slowly\n"
        "takes over.";
    pRoom->setDirectionText(ROOM_WEST, str);

    str = "The starry sky is turning black.\n"
        "The stars start winking out one by one.";
    pRoom->setDirectionText(ROOM_UP, str);

    str = "The wood beneath your feet is splintering. Worn over time\n"
        "by the salty marsh air the planks are missing and rotted.\n"
        "Tread lightly.";
    pRoom->setDirectionText(ROOM_DOWN, str);

    // create and initialize Treasure instance
    Treasure* pTreasure = new Treasure();
    str = "Treasure chest brimming with gold";
    pTreasure->setName(str);
    pTreasure->setPoints(200);
    pTreasure->setHidden(true);

    // install Treasure pointer in Room's Treasure vector
    pRoom->addTreasure(pTreasure);

    // create and initialize Bogie instance
    Bogie* pBogie = new Bogie();
    str = "Dragon";
    pBogie->setName(str);
    str = "The dragon is bound at the neck and feet.\n"
        "You must gain his trust to free him.";
    pBogie->setText(str);
    pBogie->setPoints(300);
    pBogie->setDeathText("You pry the chains off his feet with the dagger.\n"
        "You freed the dragon and saved the Mundane world from the Boglamen!\n");
    pBogie->setKillWeapon('d');

    Bogie* pBogie2 = new Bogie();
    str = "Chains";
    pBogie2->setName(str);
    str = "Chains lash the dragon to the docks.";
    pBogie2->setText(str);
    pBogie2->setDeathText("The chains around the dragon's neck are free!\n"
        "He now trusts that you are here to help and lets you approach.\n");
    pBogie2->setKillWeapon('o');

    // install Bogie pointer in Room's Bogie vector
    pRoom->addBogie(pBogie);
    pRoom->addBogie(pBogie2);

    // create and initalize MagicWord instance
    MagicWord* pMagicWord = new MagicWord();
    str = "OBLITERUS";
    pMagicWord->setName(str);
    str = "The power to destroy has been bestowed upon you.\n";
    pMagicWord->setText(str);
    pMagicWord->setPoints(50);
    pMagicWord->setId(static_cast<int>('w'));   // 'w' for weapon

    // install MagicWord pointer in Room's MagicWord vector
    pRoom->addMagicWord(pMagicWord);

    return pRoom;
}

