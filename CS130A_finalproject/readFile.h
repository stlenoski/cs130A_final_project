/*
 * hashTable.h
 *
 *  Created on: Feb 20, 2016
 *      Author: StevensMac
 */

#ifndef READFILE_H_
#define READFILE_H_
#include <stdio.h>
#include <string.h>
#include <iostream>
#include<vector>
#include "ProfileData.h"
using namespace std;
template<class T>
class readFile
{
public:
	void read(std::istream& input);

	readFile();
	void print();

private:
	profileData** info;
	int count;
	vector<string> split(string str, char delimiter);
	void putInDisk();

};



#endif /* READFILE_H_ */
