#include<iostream>
#include "TestRepository.h"
#include "Entity.h"
#include "Repository.h"
#include"assert.h"
#include<string.h>
#include<list>
using namespace std;

void testRepository()
{
	Entity e1("Maria", "B22BBB","liber");
	Entity e2("Andrei", "CJ44CCC", "ocupat");
	Entity e3("Mircea", "NT77NNN", "liber");
	Entity e4("Ana", "NT88TTT", "ocupat");
	Repository cars;
	cars.addEntity(e1);
	cars.addEntity(e2);
	cars.addEntity(e3);
	cars.addEntity(e4);
	assert(cars.dim() == 4);
	
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
