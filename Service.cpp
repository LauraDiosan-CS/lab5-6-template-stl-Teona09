#include "Service.h"


int Service::addObject(const char* n, const char* p, const char* s)
{
	if (strcmp(s, "ocupat") == 0) {
		int k = 0;
		typename list<Entity>::iterator it;
		list<Entity>objects = repo.getAll();
		for (it = objects.begin(); it != objects.end(); ++it)
			if (strcmp((*it).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking)
		{
			extra++;
			return -2;
		}
	}
	Entity e(n, p, s);
	repo.addElem(e);
	return 1;
}

int Service::delObject(const char* p)
{
	int mx = repo.size();
	typename list<Entity>::iterator it;
	list<Entity>objects = repo.getAll();
	for (it = objects.begin(); it != objects.end(); ++it)
		if (strcmp((*it).getNumber(), p) == 0)
			if (strcmp((*it).getStatus(), "liber") == 0)
			{
				repo.delElem(*it);
				return 1;
			}
			else return -2;
	return 0;
}

int Service::updateObject(const char* number, const char* n, const char* p, const char* s)
{
	if (strcmp(s, "ocupat") == 0) {
		int k = 0;
		typename list<Entity>::iterator it;
		list<Entity>objects = repo.getAll();
		for (it = objects.begin(); it != objects.end(); ++it)
			if (strcmp((*it).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking)
		{
			extra++;
			return -2;
		}
	}
	typename list<Entity>::iterator it;
	list<Entity>objects = repo.getAll();
	for (it = objects.begin(); it != objects.end(); ++it)
		if (strcmp((*it).getNumber(), p) == 0)
		{
			Entity newE(n, p, s);
			repo.updateElem((*it),newE);
			return 1;
		}
	return 0;
}

list <Entity> Service::getObjects()
{
	return repo.getAll();
}

Entity Service::getObjectFromPos(int i) {
	return repo.getElemFromPos(i);
}

int Service::getSize()
{
	return repo.size();
}

Entity Service::getObjectByNumber(const char* number)
{
	int mx = repo.size();
	typename list<Entity>::iterator it;
	list<Entity>objects = repo.getAll();
	for (it = objects.begin(); it != objects.end(); ++it)
		if (strcmp((*it).getNumber(), number) == 0)
			return (*it);
	return Entity("", "", "");
}

int Service::findObjectByNumber(const char* number)
{
	int mx = repo.size();
	typename list<Entity>::iterator it;
	list<Entity>objects = repo.getAll();
	int i=0;
	for (it = objects.begin(); it != objects.end(); ++it)
	{
		if (strcmp((*it).getNumber(), number) == 0)
			return i;
		i++;
	}
	return -1;
}

void Service::setParking(int p)
{
	parking = p;
}

int Service::enter(Entity& e)
{
	if (e.getStatus())
		if (strcmp(e.getStatus(), "ocupat") == 0)
			return -1;
		else {
			int k = 0;
			for (int i = 0; i < repo.size(); i++)
				if (strcmp(getObjectFromPos(i).getStatus(), "ocupat") == 0)
					k++;
			if (k >= parking) {
				extra++;
				return -2;
			}
		}
	Entity newE(e.getName(), e.getNumber(), "ocupat");
	repo.updateElem(e, newE);
	extra = 0;
	return 0;
}

int Service::exit(Entity& e)
{
	if (strcmp(e.getStatus(), "ocupat") == 0) {
		Entity newE(e.getName(), e.getNumber(), "liber");
		repo.updateElem(e, newE);
		extra = 0;
		return 1;
	}
	return -1;
}

Service::~Service()
{
}
