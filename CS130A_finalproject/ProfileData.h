/*
 * ProfileData.h
 *
 *  Created on: Feb 20, 2016
 *      Author: StevensMac
 */

#ifndef PROFILEDATA_H_
#define PROFILEDATA_H_
#include<string>
#include<iostream>
using namespace std;
class profileData
{
public:
	std::string getName()const;
	void setName(std::string name);
	string getAge()const;
	void setAge(string aAge);
	std::string getOccupation() const;
	void setOccupation(std::string aOcc);
	profileData(std::string aName, std::string aAge, std::string aOcc);
	profileData();
private:
	std::string name;
	std::string age;
	std::string occupation;
};




#endif /* PROFILEDATA_H_ */


