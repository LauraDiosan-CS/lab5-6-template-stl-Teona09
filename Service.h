#pragma once
#include<iostream>
#include "Entity.h"
#include "Repository.h"
using namespace std;
class Service
{
private:
	Repository repo;
public:
	Service();
	Service(const Repository&);
	void setRepo(const Repository&);
	void addObject(const char*, const char*, const char*);
	void delObject(const char* number);
	void updateObject(const char* number, const char*, const char*, const char*);
	int findObjectByNumber(const char* number);
	vector <Entity> getObjects();
	Entity getObjectByNumber(const char* number);
	int getSize();
	~Service();
};

