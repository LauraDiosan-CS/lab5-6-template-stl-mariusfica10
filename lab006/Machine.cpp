#include "Machine.h"
#include <cstddef>
#include <string.h>
#include <istream>
#include <ostream>
#include <iostream>
using namespace std;



//Desc: creates an object of Machine type
//In: -
//Out: An instance of Machine class
Machine::Machine()
{
	this->code = 0;
	this->name = NULL;
	this->recipe = NULL;
	this->price = 0.0;
}


//Desc: Creates an object of Machine Type with his atributes
//In: code, int - code of the object
//	  name, char* - name of the object 
//	  price, int - price of the object
//Out: An instance of machine class with his atributes code,name,recipe,price
Machine::Machine(int code, char* name, char* recipe,double price)
{
	this->code = code;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->recipe = new char[strlen(recipe) + 1];
	strcpy_s(this->recipe, strlen(recipe) + 1, recipe);
	this->price = price;
}

//Desc: Creates a machine object
//In:  a machine object(const)
//Out: an intance of a machine class
Machine::Machine(const Machine& obj)
{
	this->code = obj.code;
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	this->recipe = new char[strlen(obj.recipe) + 1];
	strcpy_s(this->recipe, strlen(obj.recipe) + 1, obj.recipe);
	this->price = obj.price;
}

//Desc: removes a machine object
//In: -
//Out: -
Machine::~Machine()
{
	if (this->name) {
		delete[]this->name;
		this->name = NULL;
	}
}

//Desc: access code of a machine object
//In: -
//Out: code of the object
int Machine::getCode()
{
	return this->code;
}

//Desc: access name of a machine object
//In: -
//Out: name of the object
char* Machine::getName()
{
	return this->name;
}

//Desc: access recipe of a machine object
//In: -
//Out: recipe of the object
char* Machine::getRecipe()
{
	return this->recipe;
}

//Desc: access price of a machine object
//In: -
//Out: price of the object
double Machine::getPrice()
{
	return this->price;
}

//Desc: modify the code of of a machine object
//In: int, the new code
//Out: object's code
void Machine::setCode(int code)
{
	this->code = code;
}

//Desc: modify the name of of a machine object
//In: char* , the new name
//Out: object's name
void Machine::setName(char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

//Desc: modify the recipe of of a machine object
//In: char* , the new recipe
//Out: object's recipe
void Machine::setRecipe(char* recipe)
{
	if (this->recipe) {
		delete[] this->recipe;
	}
	this->recipe = new char[strlen(recipe) + 1];
	strcpy_s(this->recipe, strlen(recipe) + 1, recipe);
}

//Desc: modify the price of of a machine object
//In: int, the new price
//Out: object's price
void Machine::setPrice(double price)
{
	this->price = price;
}

//desc: operator for copying an objects atributes
//in: const machine object machine
//out: pointer to atributes
Machine& Machine::operator=(const Machine& obj)
{
	this->setCode(obj.code);
	this->setName(obj.name);
	this->setPrice(obj.price);
	this->setRecipe(obj.recipe);
	return *this;
}

//desc: Operator of machine objects equality
//in: const machine object
//out: true/false
bool Machine::operator==(const Machine& obj)
{
	return this->code == obj.code && strcmp(this->name, obj.name) == 0 && this->price == obj.price && strcmp(this->recipe, obj.recipe) == 0;
}

//desc: Operator for output
//in: os and const object of machine type
//out: os
ostream& operator<<(ostream& os, const Machine& obj)
{
	os << obj.code << " " << obj.name << " " << obj.recipe << " " << obj.price;
	return os;
}

//desc: overload output for input
//in  : is and const object of type machine
//out : is
 istream& operator>>(istream& is, Machine& s)
 {
	 int code;
	 double price;
	 char* name = new char[20];
	 char* recipe = new char[20];
	 is >> code;
	 is >> name;
	 is >> recipe;
	 is >> price;

	 s.setCode(code);
	 s.setName(name);
	 s.setRecipe(recipe);
	 s.setPrice(price);

	 return is;
 }