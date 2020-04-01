#include "TestDomain.h"
#include "Entity.h"
#include"assert.h"
#include<string.h>

void testDomain()
{
	//default constructor
	Entity e1;
	assert(e1.getName() == NULL);
	assert(e1.getName() == NULL);
	assert(e1.getName() == NULL);
	//parameterized constructor
	Entity e2("Andrei", "B12BBB", "liber");
	assert(strcmp(e2.getName(), "Andrei")==0);
	assert(strcmp(e2.getNumber(), "B12BBB")==0);
	assert(strcmp(e2.getStatus(), "liber")==0);
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