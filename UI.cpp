#include "UI.h"

UI::UI()
{
}

UI::UI(const Service& s)
{
	serv = s;
}

void UI::setUI(const Service& s)
{
	serv = s;
}

void UI::menu()
{
	cout << '\n';
	cout << "Menu: " << '\n';
	cout << "\t 1.Add Car" << '\n';
	cout << "\t 2.Delete Car" << '\n';
	cout << "\t 3.Update Car" << '\n';
	cout << "\t 4.Print All Cars" << '\n';
	cout << "\t 0.Exit" << '\n' << '\n';
	cout << "Choose option: ";
}

void UI::stringToUppercase(char*& text)
{
	for (int i = 0; i < strlen(text); i++)
		text[i] = toupper(text[i]);
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
	if (s == 'd' or s == 'D')
		serv.addObject(n, p, "ocupat");
	else
		serv.addObject(n, p, "liber");
	delete[] n;
	delete[] p;
}

void UI::deleteObject()
{
	cout << "Numar de inmatriculare: ";
	char* p = new char[8];
	cin >> p;
	stringToUppercase(p);
	if (serv.findObjectByNumber(p) == -1)
		cout << "nu exista aceasta masina";
	else
		serv.delObject(p);
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
	if (serv.findObjectByNumber(p) == -1)
		cout << "nu exista aceasta masina";
	else
		if (s == 'd' or s == 'D')
			serv.updateObject(number, n, p, "ocupat");
		else
			serv.updateObject(number, n, p, "liber");
	delete[] n;
	delete[] p;
	delete[] number;
}

void UI::showAllObjects()
{
	int i = 0;
	vector <Entity> objects = serv.getObjects();
	while (i < serv.getSize())
	{
		cout << objects[i].getName() << " | ";
		cout << objects[i].getNumber() << " | ";
		cout << objects[i].getStatus() << endl;
		i++;
	}
}

void UI::console()
{
	int option;
	bool ok = 1;
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