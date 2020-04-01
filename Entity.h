#pragma once
#include<iostream>
#include<string>
using namespace std;
class Entity
{
private:
	char* name;
	char* number;
	char* status;
public:
	Entity();
	Entity(const char*, const char*, const char*);
	Entity(const Entity&);
	Entity(string);//TODO
	Entity& operator=(const Entity&);
	char* getName();
	char* getNumber();
	char* getStatus();
	void setName(const char*);
	void setNumber(const char*);
	void setStatus(const char*);
	bool operator==(const Entity&);
	bool operator<(const Entity&); //TODO
	~Entity();
	friend ostream& operator<<(ostream& os, Entity e);//TODO
	friend istream& operator>>(istream&, Entity&);//TODO
};

