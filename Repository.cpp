#include "Repository.h"

Repository::Repository()
{
}

void Repository::addEntity(Entity ent)
{
	repoList.push_back(ent);
}

int Repository::delEntity(Entity ent)
{
	list<Entity>::iterator it;
	it = find(repoList.begin(), repoList.end(), ent);
	if (it != repoList.end()) {
		repoList.erase(it);
		return 0;
	}
	return -1;
}



list < Entity> Repository::getAll()
{
	return repoList;
}

int Repository::dim()
{
	return repoList.size();
}

Repository::~Repository()
{
}
