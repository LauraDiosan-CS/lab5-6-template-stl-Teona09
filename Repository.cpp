#include "Repository.h"

Repository::Repository()
{
}

void Repository::addEntity(const Entity& ent)
{
	repoList.push_back(ent);
}

int Repository::delEntity(const Entity& ent)
{
	list<Entity>::iterator it;
	it = find(repoList.begin(), repoList.end(), ent);
	if (it != repoList.end()) {
		repoList.erase(it);
		return 0;
	}
	return -1;
}

void Repository::updateEntity(const Entity& ent, const char* n, const char* p, const char* s)
{
	list<Entity>::iterator it = find(repoList.begin(), repoList.end(), ent);
	if (it != repoList.end())
	{
		(*it).setName(n);
		(*it).setNumber(p);
		(*it).setStatus(s);
	}
}

int Repository::findEntity(const Entity& ent)
{
	list<Entity>::iterator it = find(repoList.begin(), repoList.end(), ent);
	if (it != repoList.end())
		return distance(repoList.begin(), it);
	return -1;
}

Entity Repository::getItemFromPos(int pos)
{
	list<Entity>::iterator it;
	int i;
	for (it = repoList.begin(), i = 0; it != repoList.end(); ++it)
		if (i == pos)
			break;
	else
			i++;
	return (*it);
}

vector <Entity> Repository::getAll()
{
	vector<Entity> objects;
	for (Entity ent : repoList)
		objects.push_back(ent);
	return objects;
}

int Repository::dim()
{
	return repoList.size();
}

Repository::~Repository()
{
}
