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
#include<forward_list>
#define CAPACITY 100
#define TABLE_SIZE 211
#include "readFile.h"

using namespace std;
template<class T>
readFile<T>::readFile()
{
	//hashtable = new T[TABLE_SIZE];
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

	//insertfriendGraph();
}
template<class T>
void readFile<T>::print()
{
	for(int i = 0; i<CAPACITY;i++)
	{	cout<<info[i]->getName()<< " "<<info[i]->getAge()<< " "<<info[i]->getOccupation()<<endl;
	//cout<<hashtable[i].getName()<< " "<<hashtable[i].getIndex()<<endl;
	}
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
		const char* name= info[i]->getName().c_str();
		const char* age = info[i]->getAge().c_str();
		const char* occupation = info[i]->getOccupation().c_str();
		fputs ( name , pFile );
		fseek ( pFile , 20+53*i , SEEK_SET );
		fputs ( age , pFile );
		fseek ( pFile , 3- strlen(age) , SEEK_CUR );
		fputs( occupation, pFile);
		fseek ( pFile , 20- strlen(occupation) , SEEK_CUR );

	}
	 //fclose(pFile);

}
template<class T>
int readFile<T>::hash(string str)
{
	int hash = 0;
	for(int i =0; i<str.length();i++)
	{
		hash = (hash * 101 +str[i]) % TABLE_SIZE;
	}
	return hash;
}

template<class T>
void readFile<T>::insertfriendGraph()
{
	for(int i =0;i<CAPACITY;i++)
	{
		int index;
		//index = hash(info[53*i]->getName());
		//hashtable[index].setName( (info[53*i]->getName()));
		//hashtable[index].setIndex(i);

	}

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
