#include "UI.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//desc: function that prints the app menu
//  in: - 
// out: - 
void UI::displayMenu()
{
	cout << "1. Scrie \"show\" pentru a afisa toate obiectele din tonomat(masina)\n";
	cout << "2. Scrie \"add {{code}} {{nume}} {{reteta}} {{pret}}\" pentru a adauga ceva in masina(tonomat)\n";
	cout << "3. Scrie \"pos {{i}}\" pentru a afisa obiectul din tonomat de pe pozitia i\n";
	cout << "4. Scrie \"update {{oldCode}} {{newName}} {{newRecipe}} {{newPrice}}\" pentru a updata masina cu codul {{oldCode}}\n";
	cout << "5. Scrie \"delete_code {{name}}\" pentru a sterge masina cu codul {{codul}}\n";
	cout << "6. Scrie \"delete_position {{i}}\" pentru a sterge masina de pe pozitia {{i}}\n";
	cout << "7. Scrie \"reteta\" pentru a afisa ingredientele pe medii pret\n";
	cout << "x. Scrie \"exit\" pentru a inchide aplicatia\n";
}

//desc: handles the add function of the app
//  in: string of the command
// out: - 
void UI::add(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());
	// cmd = 10 nume recipe 10
	
	pos = cmd.find(sep);

	token = cmd.substr(0, pos);
	int code = stoi(cmd);

	cmd.erase(0, pos + sep.length());
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	token = cmd.substr(0, pos);
	char* recipe = new char[token.length() + 1];
	strcpy_s(recipe, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	token = cmd.substr(0, pos);
	int price = stoi(cmd);

	this->service.add(code, name, recipe, price);

}

//desc: handles the update function of the app
//  in: string of the command
// out: - 
void UI::update(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);

	token = cmd.substr(0, pos);
	int code = stoi(cmd);

	cmd.erase(0, pos + sep.length());
	token = cmd.substr(0, pos);
	char* name = new char[token.length() + 1];
	strcpy_s(name, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	token = cmd.substr(0, pos);
	char* recipe = new char[token.length() + 1];
	strcpy_s(recipe, token.length() + 1, token.c_str());

	cmd.erase(0, pos + sep.length());
	token = cmd.substr(0, pos);
	int price = stoi(cmd);

	this->service.update(code, name, recipe, price);
}

//desc: shows all the objects in the repository
//  in: - 
// out: - 
void UI::showAll()
{
	vector <Machine>machines = this->service.getAll();
	int size = machines.size();
	for (int i = 0; i < size; i++)
	{
		cout << machines[i] << "\n";
	}
}

//desc: shows an object by position
//  in: the string command
// out: - 
void UI::showByPosition(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);

	token = cmd.substr(0, pos);
	int position = stoi(cmd);
	Machine result = this->service.getPosition(position);

	cout << result << endl;
	
}

//desc: handles the remove by code of an object
//  in: the string command 
// out: -
void UI::removeByCode(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);

	token = cmd.substr(0, pos);
	int code = stoi(cmd);

	this->service.removeByCode(code);
}

//desc: handles the remove by position of an object
//  in: the string command 
// out: -
void UI::remove(string cmd)
{
	string token;
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + sep.length());

	pos = cmd.find(sep);

	token = cmd.substr(0, pos);
	int position = stoi(cmd);

	this->service.remove(position);
}

//desc: constructor for the UI class
//  in: - 
// out: - 
UI::UI()
{
}

//desc: initialization class for UI
//  in: service, the service we copy
// out: -
UI::UI(Service& service)
{
	this->service = service;
}

//desc: destructor 
//  in: -
// out: -
UI::~UI()
{
}

//desc: handles the service func of showing ingredients average
//  in: -
// out: =-
void UI::showRecipes() {
	map<string, double> rez = this->service.showRecipe();
	for (map<string, double>::iterator it = rez.begin(); it != rez.end(); ++it) {
		cout << it->first << ":" << rez[it->first] << endl;
	}
}

//desc:
//  in:
// out:
void UI::runUI()
{
	bool shouldRun = true;
	string cmd;
	while (shouldRun)
	{
		this->displayMenu();
		getline(cin, cmd);
		if (cmd.find("show") != string::npos)
		{
			this->showAll();
		}
		if (cmd.find("add") != string::npos)
		{
			this->add(cmd);
		}
		if (cmd.find("position") != string::npos)
		{
			this->showByPosition(cmd);
		}
		if (cmd.find("update") != string::npos)
		{
			this->update(cmd);;
		}
		if (cmd.find("delete_code") != string::npos)
		{
			this->removeByCode(cmd);
		}
		if (cmd.find("reteta") != string::npos)
		{
			this->removeByCode(cmd);
		}
		if (cmd.find("delete_position") != string::npos)
		{
			this->remove(cmd);
		}
		if (cmd.find("exit") != string::npos)
		{
			shouldRun = false;
		}
	}
}