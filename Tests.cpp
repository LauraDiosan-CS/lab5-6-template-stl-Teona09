#include "Tests.h"

void testDomain()
{
	//default constructor
	Entity e1;
	assert(e1.getName() == NULL);
	assert(e1.getName() == NULL);
	assert(e1.getName() == NULL);
	//parameterized constructor
	Entity e2("Andrei", "B12BBB", "liber");
	assert(strcmp(e2.getName(), "Andrei") == 0);
	assert(strcmp(e2.getNumber(), "B12BBB") == 0);
	assert(strcmp(e2.getStatus(), "liber") == 0);
	////copy constructor
	Entity e3(e2);
	assert(e2 == e3);
	////setters
	e3.setName("Maria");
	e3.setNumber("CJ34CCC");
	e3.setStatus("ocupat");
	assert(strcmp(e3.getName(), "Maria") == 0);
	assert(strcmp(e3.getNumber(), "CJ34CCC") == 0);
	assert(strcmp(e3.getStatus(), "ocupat") == 0);
}

void testRepository()
{
	Entity e1("Maria", "B22BBB", "liber");
	Entity e2("Andrei", "CJ44CCC", "ocupat");
	Entity e3("Mircea", "NT77NNN", "liber");
	Entity e4("Ana", "NT88TTT", "ocupat");
	Repository cars;
	//ADD
	cars.addEntity(e1);
	cars.addEntity(e2);
	cars.addEntity(e3);
	cars.addEntity(e4);
	//DIM
	assert(cars.dim() == 4);
	//GET ALL
	assert(cars.getAll()[0] == e1);
	assert(cars.getAll()[1] == e2);
	assert(cars.getAll()[2] == e3);
	assert(cars.getAll()[3] == e4);
	//DELETE
	cars.delEntity(e3);
	assert(cars.dim() == 3);
	assert(cars.getAll()[2] == e4);
	//FIND ELEM
	assert(cars.findEntity(e3) == -1);
	assert(cars.findEntity(e1) == 0);
	//UPDATE
	cars.updateEntity(e1, "Maria", "B22BBB", "ocupat");
	e1.setStatus("ocupat");
	assert(cars.getAll()[0] == e1);
	assert(strcmp(cars.getAll()[0].getStatus(), "ocupat") == 0);
	//GET ITEM FROM POS
	assert(cars.getItemFromPos(0) == e1);
	assert(cars.getItemFromPos(1) == e2);
	assert(cars.getItemFromPos(2) == e4);
}

void testRepoFile()
{
	RepositoryFile<Entity> repo("Test.txt");
	Entity e1("Maria", "B22BBB", "liber");
	Entity e2("Andrei", "CJ44CCC", "ocupat");
	Entity e3("Mircea", "NT77NNN", "liber");
	Entity e4("Ana", "NT88TTT", "ocupat");
	Entity cars[] = { e1,e2,e3,e4 };
	//repo.addElem(e1); 
	//repo.addElem(e2); //deja in fisier
	repo.addElem(e3);
	repo.addElem(e4);
	list <Entity> newL = repo.getAll();
	assert(repo.size() == 4);
	int i = 0;
	for (list<Entity>::iterator it = newL.begin(); it != newL.end(); it++)
	{
		assert((*it) == cars[i]);
		i++;
	}
	repo.delElem(e2);
	assert(repo.size() == 3);
	assert(repo.findElem(e2) == -1);
	Entity e("Ana", "NT88NNN", "liber");
	repo.updateElem(e4, e);
	assert(repo.findElem(e4) == -1);
	assert(repo.getElemFromPos(2) == e);
	repo.delElem(e1);
	repo.saveToFile();
	repo.loadFromFile("Test.txt");
	assert(repo.size() == 2);
	repo.clearElem();
	repo.addElem(e1);
	repo.addElem(e2);
}

void testRepoTemplate()
{
	RepoTemplate<Entity> repo;
	Entity e1("Maria", "B22BBB", "liber");
	Entity e2("Andrei", "CJ44CCC", "ocupat");
	Entity e3("Mircea", "NT77NNN", "liber");
	Entity e4("Ana", "NT88TTT", "ocupat");
	Entity cars[] = { e1,e2,e3,e4 };
	repo.addElem(e1);
	repo.addElem(e2);
	repo.addElem(e3);
	repo.addElem(e4);
	list < Entity > l= repo.getAll();
	assert(repo.size() == 4);
	assert(l.front() == e1);
	list<Entity>::iterator it;
	int i = 0;
	for ( it = l.begin(); it != l.end(); it++)
	{
		assert((*it) == cars[i]);
		i++;
	}
	repo.delElem(e2);
	assert(repo.size() == 3);
	assert(repo.findElem(e2) == -1);
	Entity e("Robert", "BC33BBB", "liber");
	repo.updateElem(e1, e);
	assert(repo.findElem(e1) == -1);
	assert(repo.getElemFromPos(0) == e);
}

void testService()
{
	Entity e1("Maria", "B22BBB", "liber");
	Entity e2("Andrei", "CJ44CCC", "ocupat");
	Entity e3("Mircea", "NT77NNN", "liber");
	Entity e4("Ana", "NT88TTT", "ocupat");
	RepoTemplate<Entity> cars;
	//COSTRUCTOR
	Service serv(cars);
	//SET PARKING
	serv.setParking(2);
	//ADD
	int rez = 0;
	rez = serv.addObject("Maria", "B22BBB", "liber");
	rez = serv.addObject("Andrei", "CJ44CCC", "ocupat");
	rez = serv.addObject("Mircea", "NT77NNN", "liber");
	rez = serv.addObject("Ana", "NT88TTT", "liber"); 
	//GET SIZE
	assert(serv.getSize() == 4);
	//DELETE
	rez = serv.delObject("NT77NNN");
	assert(serv.getSize() == 3);
	//FIND PROJECT - returns the position
	assert(serv.findObjectByNumber("NT77NNN") == -1); ////no object with this number in database
	assert(serv.findObjectByNumber("NT88TTT") == 2);
	//GET OBJECTS
	list < Entity > l = serv.getObjects();
	assert(serv.getSize() == 3);
	assert(l.front() == e1);
	list<Entity>::iterator it;
	int i = 0;
	Entity arrayCars[] = { e1,e2,e4};
	for (it = l.begin(); it != l.end(); it++)
	{
		assert(strcmp((*it).getNumber(), arrayCars[i].getNumber())==0);
		i++;
	}
	//GET OBJECT BY NUMBER
	Entity e_NULL("", "", "");
	assert(serv.getObjectByNumber("NT77NNN") == e_NULL); //no object with this number in database
	//assert(serv.getObjectByNumber("NT88TTT") == e4);
	//UPDATE
	rez = serv.updateObject("B22BBB", "Mara", "B22BBB", "ocupat");
	assert(strcmp(serv.getObjectByNumber("B22BBB").getName(), "Mara") == 0);
	assert(strcmp(serv.getObjectByNumber("B22BBB").getStatus(), "ocupat") == 0);
	//ENTER PARKING
	assert(serv.extra == 0);
	Entity e("Ana", "NT88TTT", "ocupat");
	rez = serv.enter(e);
	assert(serv.extra == 0);
	//assert(strcmp(serv.getObjectByNumber("NT88TTT").getStatus(), "ocupat") == 0);
	//EXIT PARKING
	rez = serv.exit(e);
	assert(strcmp(serv.getObjectByNumber("NT88TTT").getStatus(), "liber") == 0);
}