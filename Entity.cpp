#include "Entity.h"

Entity::Entity()
{
	name = NULL;
	number = NULL;
	status = NULL;
}

Entity::Entity(const char* n, const char* p, const char* s)
{
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
	this->number = new char[strlen(p) + 1];
	strcpy_s(this->number, strlen(p) + 1, p);
	this->status = new char[strlen(s) + 1];
	strcpy_s(this->status, strlen(s) + 1,s);
}

Entity::Entity(const Entity& ent)
{
	this->name = new char[strlen(ent.name) + 1];
	strcpy_s(this->name, strlen(ent.name) + 1, ent.name);
	this->number = new char[strlen(ent.number) + 1];
	strcpy_s(this->number, strlen(ent.number) + 1, ent.number);
	this->status = new char[strlen(ent.status) + 1];
	strcpy_s(this->status, strlen(ent.status) + 1, ent.status);
}

Entity& Entity::operator=(const Entity& ent)
{
	if (this == &ent) return *this;
	if (ent.name)
	{
		if (name) delete[] name;
		name = new char[strlen(ent.name) + 1];
		strcpy_s(name, strlen(ent.name) + 1, ent.name);
	}
	if (ent.number)
	{
		if (number) delete[] number;
		number = new char[strlen(ent.number) + 1];
		strcpy_s(number, strlen(ent.number) + 1, ent.number);
	}
	if (ent.status)
	{
		if (status) delete[] status;
		status = new char[strlen(ent.status) + 1];
		strcpy_s(status, strlen(ent.status) + 1, ent.status);
	}
	return *this;
}

char* Entity::getName()
{
	return name;
}

char* Entity::getNumber()
{
	return number;
}

char* Entity::getStatus()
{
	return status;
}

void Entity::setName(const char* n)
{
	if (name) delete[] name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Entity::setNumber(const char* p)
{
	if (number) delete[] number;
	number = new char[strlen(p) + 1];
	strcpy_s(number, strlen(p) + 1, p);
}

void Entity::setStatus(const char* s)
{
	if (status) delete[] status;
	status = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}


bool Entity::operator==(const Entity& ent)
{
	return(strcmp(name, ent.name) == 0) and (strcmp(number, ent.number) == 0) and \
		(strcmp(status, ent.status) == 0);
}

Entity::~Entity()
{
	if (name) delete[] name;
	name = NULL;
	if (number) delete[] number;
	number = NULL;
	if (status) delete[] status;
	status = NULL;
}