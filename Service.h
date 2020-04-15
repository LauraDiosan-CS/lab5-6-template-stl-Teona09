#pragma once
#include"Entity.h"
#include"RepositoryFile.h"
#include"RepoTemplate.h"

class Service
{
private:
	RepoTemplate<Entity>& repo;
public:
	int parking=0;
	int extra=0;
	//Service();
	Service(RepoTemplate<Entity>& r) :repo(r) { repo = r; };
	int addObject(const char*, const char*, const char*);
	int delObject(const char* number);
	int updateObject(const char* number, const char*, const char*, const char*);
	int findObjectByNumber(const char* number);
	list <Entity> getObjects();
	Entity getObjectByNumber(const char* number);
	Entity getObjectFromPos(int);
	int getSize();
	int enter(Entity&);
	int exit(Entity&);
	void setParking(int);
	~Service();
};

