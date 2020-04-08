#pragma once
#include<iostream>
#include "Entity.h"
#include "RepositoryFile.h"
using namespace std;
class Service
{
private:
	RepositoryFile repo;
	int psize;
public:
	Service();
	Service(const RepositoryFile&);
	void setRepo(const RepositoryFile&);
	void initService(const char *);
	void addObject(const char*, const char*, const char*);
	void delObject(const char* number);
	void updateObject(const char* number, const char*, const char*, const char*);
	int findObjectByNumber(const char* number);
	vector <Entity> getObjects();
	Entity getObjectByNumber(const char* number);
	int getSize();
	void enter(Entity&);
	~Service();
};

