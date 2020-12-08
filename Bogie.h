/******************************************************************************
* Cathy Strunk (Shands)
* Bogie.h
* CS 281-0798, Fall 2020
*
* Bogie class declaration
*******************************************************************************
*/
#ifndef BOGIE_H
#define BOGIE_H

#include <string>
#include <vector>

#include "CarryIt.h"

class Bogie : public CarryIt
{
private:
	int m_lifeStatus;
	std::string m_deathText;
	char m_killWeapon;
public:
	Bogie();
	Bogie(std::string bName);
	bool setLifeStatus(int);
	bool getLifeStatus();

	bool setDeathText(const std::string& text);
	std::string& getDeathText(std::string& text) const;

	bool setKillWeapon(char kWInit);
	char getKillWeapon();

	// must implement pure virtual base class member function
	bool setId(int id);
};

#endif
