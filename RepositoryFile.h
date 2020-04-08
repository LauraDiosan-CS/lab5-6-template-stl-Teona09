#pragma once
#include<iostream>
#include<list>
#include"Entity.h"
#include"Repository.h"
using namespace std;
class RepositoryFile : public Repository 
{
private:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	void loadFromFile(const char*);
	void saveToFile();
	~RepositoryFile();
};

