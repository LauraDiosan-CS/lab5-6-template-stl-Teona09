#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include "Entity.h"
#include "RepoTemplate.h"
using namespace std;

template<class T> class RepositoryFile : public RepoTemplate <Entity>
{
protected:
	const char* filename;
public:
	RepositoryFile() {
		filename = "";
	}

	RepositoryFile(const char* file) {
		this->loadFromFile(file);
	}

	void addElem(const T& e) {
		RepoTemplate<Entity>::addElem(e);
		this->saveToFile();
	}

	int delElem(const T& e) {
		int r = RepoTemplate<Entity>::delElem(e);
		if (r != 0) {
			this->saveToFile();
			return 0;
		}
		else
			return -1;
	}
	
	void updateElem(const T& e, const T n) {
		RepoTemplate<Entity>::updateElem(e, n);
		this->saveToFile();
	}

	void loadFromFile(const char* file) {
		RepoTemplate<Entity>::clearElem();
		filename = file;
		ifstream f(file);
		char* name = new char[10];
		char* numar = new char[10];
		char* status = new char[10];
		while (!f.eof())
		{
			f >> name >> numar >> status;
			if (strcmp(name, "") != 0)
			{
				Entity e(name, numar, status);
				//elem.push_back(e);
				RepoTemplate<Entity>::addElem(e);
			}
		}
		delete[] name;
		delete[] numar;
		delete[] status;
		f.close();
	}

	void saveToFile() {
		ofstream f(filename);
		typename list<Entity>::iterator it;
		list<Entity>elem = RepoTemplate<Entity>::getAll();
		for (it = elem.begin(); it != elem.end(); ++it)
		{
			f << (*it).getName() << " " << (*it).getNumber() << " " << (*it).getStatus() << '\n';
		}
		f.close();
	}

	~RepositoryFile() {};
};
