/*
 * readFile.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: StevensMac
 */

#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include<fstream>
#define CAPACITY 100
#include "readFile.h"

using namespace std;
template<class T>
readFile<T>::readFile()
{
	info = new T*[CAPACITY];
	count = 0;
}

template<class T>
void readFile<T>::read(std::istream& input)
{
	string name;
	if(!input) cerr << "File not found" << endl;
	else
	{
		int index = 0;
		while(!input.eof())
		{
			info[index] = new T;
			string line;
			std::getline(input, line);
			vector<string> words = split(line, ',');
			info[index]->setName((string)words[0]);
			info[index]->setAge((string)words[1]);
			info[index]->setOccupation((string)words[2]);
			index++;
			count++;
		}
		putInDisk();

	}
}
template<class T>
void readFile<T>::print()
{
	for(int i = 0; i<CAPACITY;i++)
		cout<<info[i]->getName()<< " "<<info[i]->getAge()<< " "<<info[i]->getOccupation()<<endl;
}
template<class T>
vector<string> readFile<T>::split(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);       // turn the string into a stream.
	string tok;

	while(getline(ss, tok, delimiter))
	{

		internal.push_back(tok);

	}

	return internal;
}


template<class T>
void readFile<T>::putInDisk()
{
FILE * pFile;
pFile = fopen ( "ProfileData.txt" , "w" );
for(int i = 0;i<count;i++)
{
	//char* name =(char*)info[i]->getName();
	fputs ( info[i]->getName().c_str() , pFile );
	fseek ( pFile , 20+20*i , SEEK_SET );
	fputs ( info[i]->getAge().c_str() , pFile );
	fseek ( pFile , 3- strlen((char*) info[i]->getAge().c_str()) , SEEK_CUR );
	fputs( info[i]->getOccupation().c_str(), pFile);
}

fseek(pFile,54,SEEK_SET);
fputs("+",pFile);
fclose ( pFile );

}
int main()
{
	string name;
	ifstream f;
	readFile<profileData> h;
	f.open("InputFile.txt");
	h.read(f);
	h.print();
}
