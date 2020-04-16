#pragma once
#include "RepoSTL.h"
#include "Repo.h"
#include "Machine.h"
#include <set>
#include <map>

class Service
{
private:
	RepoSTL<Machine> repoSTL;
public:
	Service();
	Service(RepoSTL<Machine>& repository);
	~Service();

	void setRepository(RepoSTL<Machine>& repository);

	void add(int code, char* name, char* recipe, double price);

	vector <Machine> getAll();

	Machine getPosition(int pos);
	void update(int code, char* newName, char* newRecipe, double newPrice);
	void removeByCode(const int code);
	void remove(int pos);
	int getSize();
	map<string , double> showRecipe();
};