#include "RepositoryFile.h"
#include <fstream>
RepositoryFile::RepositoryFile()
{
	fileName = "";
}

RepositoryFile::RepositoryFile(const char* file) : Repository()
{
	repoList.clear();
	fileName = file;
	ifstream f(file);
	char* name = new char[20];
	char* number = new char[20];
	char* status = new char[20];
	char* blank =new char[20];
	while (f >> name >> number >> status)
	{
		//f >> name >> number >> status;
		if (name != "") {
			Entity e(name, number, status);
			repoList.push_back(e);
		}
	}
	delete[] name;
	delete[] number;
	delete[] status;
	f.close();
}

void RepositoryFile::loadFromFile(const char* file)
{
	repoList.clear();
	fileName = file;
	ifstream f(file);
	char* name = new char[20];
	char* number = new char[20];
	char* status = new char[20];
	//while (!f.eof())
	char* blank = new char[20];
	while (f >> name >> number >> status)
	{
		f >> name >> number >> status;
		if (strcmp(name, "") != 0)
		{
			Entity e(name, number, status);
			repoList.push_back(e);
		}
	}
	delete[] name;
	delete[] number;
	delete[] status;
	f.close();
}
void RepositoryFile::saveToFile()
{
	ofstream f(fileName);
	for (int i = 0; i < repoList.size(); i++)
	{
		f << getItemFromPos(i).getName() << " " << getItemFromPos(i).getNumber() << " " << getItemFromPos(i).getStatus() << '\n';
	}
	f.close();
}
RepositoryFile::~RepositoryFile()
{
}
