#pragma once
#include<iostream>
#include<list>
#include<iterator>
#include<string>
#include"Entity.h"
using namespace std;

class Repository
{
private:
	list <Entity> repoList;
public:
	Repository();
	void addEntity(Entity);
	int delEntity(Entity); 
	void updateEntity(Entity, char*, int); //TODO
	bool findEntity(Entity);//TODO
	Entity getItemFromPos(int);//TODO
	list <Entity> getAll();
	int dim();
	~Repository();
};

