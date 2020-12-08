/******************************************************************************
* Cathy Strunk (Shands)
* CarryIt.cpp
* CS 281-0798, Fall 2020
*
* CarryIt pure abstract class definition
*******************************************************************************
*/
#include <string>

#include "CarryIt.h"


//***********************************************************
// CarryIt()
//
// constructor
//***********************************************************
CarryIt::CarryIt()
{
    m_id = -1;
    m_name = "carry me";
    m_text = "";
    m_points = 0;
    m_roomNow = 0;
    m_playerNow = 0;
    m_hidden = false;
}

//***********************************************************
// setId() declared as pure virtual
//***********************************************************

//***********************************************************
// getId() 
//***********************************************************
int CarryIt::getId() const
{
    return m_id;
}

//***********************************************************
// setName()
//***********************************************************
bool CarryIt::setName(std::string& name)
{
    m_name = name;
    return true;
}

//***********************************************************
// getName()
//***********************************************************
bool CarryIt::getName(std::string& name) const
{
    name = m_name;
    return true;
}

//***********************************************************
// setPoints()
//***********************************************************
bool CarryIt::setPoints(int points)
{
    m_points = points;
    return true;
}

//***********************************************************
// getPoints()
//***********************************************************
int CarryIt::getPoints() const
{
    return m_points;
}

//***********************************************************
// setText()
//***********************************************************
bool CarryIt::setText(std::string& text)
{
    m_text = text;
    return true;
}

//***********************************************************
// getText()
//***********************************************************
bool CarryIt::getText(std::string& text) const
{
    text = m_text;
    return true;
}

//***********************************************************
// setHidden()
//***********************************************************
bool CarryIt::setHidden(bool hide)
{
    m_hidden = hide;
    return true;
}

//***********************************************************
// getHidden()
//***********************************************************
bool CarryIt::getHidden()
{
    return m_hidden;
}