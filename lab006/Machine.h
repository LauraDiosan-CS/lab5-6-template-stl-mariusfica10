#pragma once
#include <ostream>
using namespace std;

//creating a machine object
class Machine
{
private:
	int code;
	char* name;
	char* recipe;
	double price;
public:
	Machine();
	Machine(int code, char* name,char* recipe, double price);
	Machine(const Machine& obj);
	~Machine();
	int getCode();
	char* getName();
	char* getRecipe();
	double getPrice();
	void setCode(int code);
	void setName(char* name);
	void setRecipe(char* recipe);
	void setPrice(double price);
	Machine& operator = (const Machine& obj);
	bool operator == (const Machine& obj);
	friend ostream& operator << (ostream& os, const Machine& obj);
	friend istream& operator>>(istream& is, Machine& s);
};