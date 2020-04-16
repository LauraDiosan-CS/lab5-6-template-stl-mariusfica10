#include "Service.h"
#include "RepoSTL.h"
#include <cstring>
#include <map>
#include <iostream>
#include <iterator>
using namespace std;

//desc: constructor for service class
//  in: -
// out: -
Service::Service()
{
}

//desc: sets a repository
//  in: the repository to copy
// out: -
Service::Service(RepoSTL<Machine>& repository)
{
	this->repoSTL = repository;
}

//desc: destructor 
//  in: - 
// out: -
Service::~Service()
{
}

//desc: sets a repository
//  in: repository to copy
// out: -
void Service::setRepository(RepoSTL<Machine>& repository)
{
	this->repoSTL = repository;
}

//desc:adds an object to repo
//  in: atributes for an object
// out: - 
void Service::add(int code, char* name, char* recipe, double price)
{
	this->repoSTL.add(Machine(code, name, recipe, price));
}

//desc:shows all the objects in the repo
//  in: -
// out: all objects
vector<Machine> Service::getAll()
{
	return this->repoSTL.getAll();
}

//desc: returns an object by position in list
//  in: pos, the position of the element, we want to show(integer)
// out: the object we want
Machine Service::getPosition(int pos)
{
	return this->repoSTL.getPosition(pos);

}

//desc: returns the number of componets in service
//  in: -
// out: number of components
int Service::getSize()
{
	return this->repoSTL.getSize();
}

//desc: returns a map with ingredients and their average price in the objects
//in  : -
//out : the map with ingredients
map<string, double> Service::showRecipe()
{
	map<string, double> rez;
	map<string, int> cnt;
	
	vector<Machine> prajituri = this->repoSTL.getAll();
	for (int j = 0; j < prajituri.size(); j++)
	{
		char* token = NULL;
		char* context = NULL;
		token = strtok_s(prajituri[j].getRecipe(), ",", &context);
		
		while (token)
		{
			map<string, double>::iterator i = rez.find(string(token));
			if (i == rez.end())
			{
				rez[string(token)] = prajituri[j].getPrice();
				cnt[string(token)] = 1;
			}
			else
			{
				rez[string(token)] += prajituri[j].getPrice();
				cnt[string(token)] += 1;
			}
			token = strtok_s(NULL, ",", &context);
		}

	}
	for (map<string, double>::iterator it = rez.begin(); it != rez.end(); ++it)
	{
		it->second = it->second / cnt[it->first];
	}
	return rez;
}
//desc: updates an element by the code
//  in: new atribute values, except code
// out: - 
void Service::update(int code, char* newName, char* newRecipe, double newPrice)
{
	vector<Machine> machines = this->repoSTL.getAll();
	Machine newMachine(code, newName, newRecipe, newPrice);
	for (int i = 0; i < this->repoSTL.getSize(); i++)
	{
		if (machines[i].getCode() == code)
		{
			Machine oldMachine(code, machines[i].getName(), machines[i].getRecipe(), machines[i].getPrice());
			this->repoSTL.update(oldMachine, newMachine);
			return;
		}
	}
}

//desc: removes an object by code of the product
//  in: code of the object we want to delete(integer)
// out: -
void Service::removeByCode(const int code)
{
	vector <Machine> machines = this->repoSTL.getAll();
	for (int i = 0; i < this->repoSTL.getSize(); i++)
	{
		if ( machines[i].getCode() == code)
		{
			Machine item = this->repoSTL.getPosition(i);
			this->repoSTL.remove(item);
		}
	}
	this->repoSTL.saveToFile();
}

//desc: removes an object by position in list
//  in: position of the object we want to delete(integer)
// out: - 
void Service::remove(int pos)
{
	if (pos >= 0 and pos < this->repoSTL.getSize())
	{
		Machine item = this->repoSTL.getPosition(pos);
		this->repoSTL.remove(item);
	}
	this->repoSTL.saveToFile();
}


