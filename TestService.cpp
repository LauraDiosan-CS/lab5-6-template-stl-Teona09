#include"TestService.h"

void testService()
{
	Entity e1("Maria", "B22BBB", "liber");
	Entity e2("Andrei", "CJ44CCC", "ocupat");
	Entity e3("Mircea", "NT77NNN", "liber");
	Entity e4("Ana", "NT88TTT", "ocupat");
	Repository cars;
	cars.addEntity(e1);
	cars.addEntity(e2);
	//COSTRUCTOR
	Service serv(cars);
	//ADD
	serv.addObject("Mircea", "NT77NNN", "liber");
	serv.addObject("Ana", "NT88TTT", "ocupat");
	//GET SIZE
	assert(serv.getSize() == 4);
	//DELETE
	serv.delObject("NT77NNN");
	assert(serv.getSize() == 3);
	//FIND PROJECT - returns the position
	assert(serv.findObjectByNumber("NT77NNN") == -1); ////no object with this number in database
	assert(serv.findObjectByNumber("NT88TTT") == 2);
	//GET OBJECTS
	assert(serv.getObjects()[0] == e1);
	assert(serv.getObjects()[1] == e2);
	assert(serv.getObjects()[2] == e4);
	//GET OBJECT BY NUMBER
	Entity e_NULL("", "", "");
	assert(serv.getObjectByNumber("NT77NNN") == e_NULL); //no object with this number in database
	assert(serv.getObjectByNumber("NT88TTT") == e4);
	//UPDATE
	serv.updateObject("B22BBB", "Maria Popescu", "B22BBB", "ocupat");
	assert(strcmp(serv.getObjectByNumber("B22BBB").getName(), "Maria Popescu")==0);
	assert(strcmp(serv.getObjectByNumber("B22BBB").getStatus(),"ocupat")==0);
}