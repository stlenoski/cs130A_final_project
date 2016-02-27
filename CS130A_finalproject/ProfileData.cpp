/*
 * ProfileData.cpp

 *
 *  Created on: Feb 20, 2016
 *      Author: StevensMac
 */
#include "ProfileData.h"
std::string profileData::getName() const
{
	return name;
}
void profileData::setName(std::string aName)
{
	name = aName;
}
std::string profileData::getAge() const
{
	return age;
}
void profileData::setAge(string aAge)
{
	age = aAge;
}
std::string profileData::getOccupation() const
{
	return occupation;
}
void profileData::setOccupation(std::string aOcc)
{
	occupation = aOcc;
}
profileData::profileData(std::string aName,std::string aAge,std::string aOcc)
{
	name = aName;
	age = aAge;
	occupation = aOcc;
}
profileData::profileData()
{
	name= "";
	age = "";
	occupation = "";
}




