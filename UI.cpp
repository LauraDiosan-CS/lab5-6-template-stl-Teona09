#include "UI.h"

void UI::menu()
{
	cout << '\n';
	cout << "Menu: " << '\n';
	cout << "\t 1.Add Car" << '\n';
	cout << "\t 2.Delete Car" << '\n';
	cout << "\t 3.Update Car" << '\n';
	cout << "\t 4.Print All Cars" << '\n';
	cout << "\t 5.Enter parking" << '\n';
	cout << "\t 6.Exit parking" << '\n';
	cout << "\t 7.How many cars tried to enter but didn't have space?" << '\n';
	cout << "\t 0.Exit" << '\n' << '\n';
	cout << "Choose option: ";
}

void UI::stringToUppercase(char*& text)
{
	unsigned int n = strlen(text);
	for (int i = 0; i < n; i++)
		text[i] = toupper(text[i]);
}

void UI::enterParking()
{
	char* number = new char[20];
	cout << "Numar de inmatriculare: ";
	cin >> number;
	Entity e;
	int size = serv.getSize();
	for (int i = 0; i < serv.getSize(); i++)
		if (strcmp(serv.getObjectFromPos(i).getNumber(), number) == 0)
			e = serv.getObjectFromPos(i);
	if (serv.findObjectByNumber(e.getNumber()) != -1) {
		int rez = serv.enter(e);
		if (rez == -1)
			cout << "masina este deja in parcare" << endl;
		else if (rez == -2)
			cout << "spatiu insuficient" << endl;
		else if (rez == 0)
			cout << "masina a fost adaugata in parcare" << endl;
	}
	else
		cout << "masina nu exista" << endl;
	delete []number;
}

void UI::exitParking()
{
	char* number = new char[20];
	cout << "Numar de inmatriculare: ";
	cin >> number;
	Entity e;
	for (int i = 0; i < serv.getSize(); i++)
		if (strcmp(serv.getObjectFromPos(i).getNumber(), number) == 0)
			e = serv.getObjectFromPos(i);
	if (serv.findObjectByNumber(e.getNumber()) != -1) {
		int rez = serv.exit(e);
		if (rez == -1)
			cout << "masina nu este in parcare" << endl;
		else if (rez == 0)
			cout << "masina a fost adaugata in parcare" << endl;
	}
	else
		cout << "masina nu exista" << endl;
	delete[]number;
}

void UI::addObject()
{
	char* n = new char[32];
	char* p = new char[8];
	char s;
	cout << "Nume Posesor: ";
	cin >> n;
	cout << "Nr de inmatriculare: ";
	cin >> p;
	stringToUppercase(p);
	cout << "Ocupat? (D/N): ";
	cin >> s;
	int rez;
	if (s == 'd' or s == 'D')
		rez=serv.addObject(n, p, "ocupat");
	else
		rez=serv.addObject(n, p, "liber");
	if (rez == 1)
		cout << "masina adaugata";
	else if (rez == -2)
		cout << "spatiu insuficient";
	delete[] n;
	delete[] p;
}

void UI::deleteObject()
{
	cout << "Numar de inmatriculare: ";
	char* p = new char[8];
	cin >> p;
	stringToUppercase(p);
	int rez=0;
	if (serv.findObjectByNumber(p) == -1)
		cout << "nu exista aceasta masina";
	else
		rez=serv.delObject(p);
	if (rez == 1)
		cout << "masina stearsa";
	else if (rez == -2)
		cout << "masina este inca in parcare";
}

void UI::updateObject()
{
	cout << "Numar de inmatriculare: ";
	char* number = new char[8];
	cin >> number;
	stringToUppercase(number);

	char* n = new char[32];
	char* p = new char[8];
	char s;
	cout << "Nume Posesor: ";
	cin >> n;
	cout << "Nr de inmatriculare: ";
	cin >> p;
	stringToUppercase(p);
	cout << "Ocupat? (D/N): ";
	cin >> s;
	int rez=0;
	if (serv.findObjectByNumber(p) == -1)
		cout << "nu exista aceasta masina";
	else
		if (s == 'd' or s == 'D')
			rez = serv.updateObject(number, n, p, "ocupat");
		else
			rez = serv.updateObject(number, n, p, "liber");
	if (rez == 1)
		cout << "masina actualizata";
	else if (rez == -2)
		cout << "spatiu insuficient";
	delete[] n;
	delete[] p;
	delete[] number;
}

void UI::showAllObjects()
{
	typename list<Entity>::iterator it;
	list<Entity>objects = serv.getObjects();
	for (it = objects.begin(); it != objects.end(); ++it)
	{
		cout << (*it).getName() << " | ";
		cout << (*it).getNumber() << " | ";
		cout << (*it).getStatus() << endl;
	}
}

void UI::console()
{
	int option;
	bool ok = 1;
	int locuri;
	cout << "nr de locuri din parcare este: ";
	cin >> locuri;
	serv.setParking(locuri);
	while (ok)
	{
		menu();
		cin >> option;
		cout << '\n';
		switch (option)
		{
		case 1:
		{
			addObject();
			break;
		}
		case 2:
		{
			deleteObject();
			break;
		}
		case 3:
		{
			updateObject();
			break;
		}
		case 4:
		{
			showAllObjects();
			break;
		}
		case 5:
		{
			enterParking();
			break;
		}case 6:
		{
			exitParking();
			break;
		}case 7:
		{
			cout << serv.extra;
			break;
		}
		case 0:
		{
			cout << "See you next time :)\n";
			ok = 0;
			break;
		}
		default:
		{
			cout << "Not an option" << '\n';
			break;
		}
		}
	}
}

UI::~UI()
{
}