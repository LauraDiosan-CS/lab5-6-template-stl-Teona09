#pragma once
#include<iostream>
#include"Service.h"
using namespace std;

class UI
{
private:
	Service serv;
public:
	UI();
	UI(const Service&);
	void setUI(const Service&);
	void menu();
	void stringToUppercase(char*&);
	void addObject();
	void deleteObject();
	void updateObject();
	void showAllObjects();
	void console();
	~UI();
};

