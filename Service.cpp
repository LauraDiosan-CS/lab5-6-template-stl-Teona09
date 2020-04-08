#include "Service.h"

Service::Service()
{
}

Service::Service(const RepositoryFile& r)
{
	repo = r;
}

void Service::setRepo(const RepositoryFile& r)
{
	repo = r;
	//repo.saveToFile();
}

//void Service::initService(const char* fileName)
//{
//	repo.loadFromFile(fileName);
//}

void Service::addObject(const char* n, const char* p, const char* s)
{
	Entity e(n,p,s);
	repo.addEntity(e);
	repo.saveToFile();
}

void Service::delObject(const char* p)
{
	int mx = repo.dim();
	vector<Entity>objects;
	objects = repo.getAll();
	for (int i = 0; i < mx; i++)
		if (strcmp(objects[i].getNumber(), p) == 0)
		{
			repo.delEntity(objects[i]);
			break;
		}
	//repo.saveToFile();
}

void Service::updateObject(const char* number,const char* n,const char* p,const char* s)
{
	int mx = repo.dim();
	vector<Entity>objects;
	objects = repo.getAll();
	for (int i = 0; i < mx; i++)
		if (strcmp(objects[i].getNumber(), p) == 0)
		{
			repo.updateEntity(objects[i],n,p,s);
			break;
		}
	//repo.saveToFile();
}

vector <Entity> Service::getObjects()
{
	return repo.getAll();
}

int Service::getSize()
{
	return repo.dim();
}

Entity Service::getObjectByNumber(const char *number)
{
	int mx = repo.dim();
	vector<Entity>objects;
	objects = repo.getAll();
	for (int i = 0; i < mx; i++)
		if (strcmp(objects[i].getNumber(), number) == 0)
			return objects[i];
	return Entity("", "", "");
}

int Service::findObjectByNumber(const char* number)
{
	int mx = repo.dim();
	vector<Entity>objects;
	objects = repo.getAll();
	for (int i = 0; i < mx; i++)
		if (strcmp(objects[i].getNumber(), number) == 0)
			return i;
	return -1;
}

Service::~Service()
{
}
