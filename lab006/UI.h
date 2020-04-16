#pragma once
#include "Service.h"

class UI
{
private:
	Service service;
	void displayMenu();
	void add(string cmd);
	void update(string cmd);
	void showAll();
	void showByPosition(string cmd);
	void removeByCode(string cmd);
	void remove(string cmd);
	void showRecipes();
public:
	UI();
	UI(Service& service);
	~UI();
	void runUI();
};
