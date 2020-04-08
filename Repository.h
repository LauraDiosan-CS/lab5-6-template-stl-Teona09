#pragma once
#include<iostream>
#include<list>
#include<iterator>
#include<vector>
#include"Entity.h"
using namespace std;

class Repository
{
private:
	list <Entity> repoList;
public:
	Repository();
	void addEntity(const Entity&);
	int delEntity(const Entity&);
	void updateEntity(const Entity&, const char*, const char*, const char*); //TODO
	int findEntity(const Entity&);
	Entity getItemFromPos(int);//TODO
	vector <Entity> getAll();
	int dim();
	~Repository();
};

