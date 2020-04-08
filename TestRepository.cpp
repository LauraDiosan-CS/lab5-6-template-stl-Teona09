#include "TestRepository.h"
#include<iostream>
using namespace std;

void testRepository()
{
	Entity e1("Maria", "B22BBB","liber");
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
<<<<<<< HEAD
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
	assert(strcmp(cars.getAll()[0].getStatus(),"ocupat")==0);
	//GET ITEM FROM POS
	assert(cars.getItemFromPos(0) == e1);
	assert(cars.getItemFromPos(1) == e2);
	assert(cars.getItemFromPos(2) == e4);
}
=======
	
	Entity carsArray[] = { e1,e2,e3,e4 };
	list <Entity> cars2;
	cars2 = cars.getAll();
	list <Entity>::iterator it;
	int i=0;
	for (it = cars2.begin(); it != cars2.end() and i < 4; ++it)
	{
		assert(*it == carsArray[i]);
		//cout << carsArray[i].getName();
		i++;

	}

	assert(cars2.front() == e1);
	assert(cars2.back() == e4);
}
>>>>>>> cf0dd4258d7736eefd6803cd54af71e7b9066342
