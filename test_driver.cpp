/******************************************************************************
* Cathy Strunk (Shands)
* app.cpp
* CS 281 - 0798, Fall 2020
*
* App main with entry point main()
*******************************************************************************
*/

#include <iostream>

#include "MagicWord.h"

// local function prototypes
void displayUse(MagicWord* pMW);

/******************************************************************************
* int main()
* entry point
*******************************************************************************
*/
int main()
{
    // first MagicWord
    // declare MagicWord class (reveal)
    MagicWord* pMagicWord = new MagicWord();

    // set magic word name and points
    std::string str;
    str = "MOBIATE";
    pMagicWord->setName(str);
    pMagicWord->setPoints(25);
    
    // set magic word text (what it does)
    str = "Reveals a treasure";
    pMagicWord->setText(str);
    
    // set id (for tracking use [reveal vs weapon])
    pMagicWord->setId(static_cast<int>('r')); // 'r' means reveal

    // second MagicWord
    // declare MagicWord class (weapon)
    MagicWord* pMagicWord2 = new MagicWord();

    // set magic word name and points
    str = "REPELUS";
    pMagicWord2->setName(str);
    pMagicWord2->setPoints(50);

    // set magic word text (what it does)
    str = "Repels Grausters";
    pMagicWord2->setText(str);

    // set id
    pMagicWord2->setId(static_cast<int>('w')); // 'w' means weapon 

    // display magic words and points
    pMagicWord->getName(str);
    std::cout << "Magic Word 1: " << str;
    std::cout << " worth " << pMagicWord->getPoints() << " points.\n";
    pMagicWord2->getName(str);
    std::cout << "Magic Word 2: " << str;
    std::cout << " worth " << pMagicWord2->getPoints() << " points.\n";

    // display magic words use dependent on id
    displayUse(pMagicWord);
    displayUse(pMagicWord2);

    system("pause");

    return 0;
}

void displayUse(MagicWord* pMW)
{
    int id = pMW->getId();
    std::string str;
    if (id == static_cast<int>('r'))
    {
        std::cout << "Use: Reveal - ";
        pMW->getText(str);
        std::cout << str << std::endl;
    }
    else
    {
        std::cout << "Use: Weapon - ";
        pMW->getText(str);
        std::cout << str << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
