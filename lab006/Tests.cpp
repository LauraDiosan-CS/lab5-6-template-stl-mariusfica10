#include "Tests.h"
#include "Machine.h"
#include "Repo.h"
#include "RepoSTL.h"
#include "Service.h"
#include <assert.h>
#include <iostream>
using namespace std;

//tests for machine class
//constructors, destructor, overload operators
//getters,setters
//in  :
//out :
void testDomain()
{
	Machine product1(11,(char*)"boabe",(char* )"xanax",10.5);
	Machine product2;
	
	assert(product1.getCode() == 11);
	assert(strcmp(product1.getName(),"boabe") == 0);
	assert(strcmp(product1.getRecipe(), "xanax") == 0);
	assert(product1.getPrice() == 10.5);
	
	product2 = product1;
	
	assert(product2 == product1);
	
	product2.setCode(20);
	product2.setName((char*)"multe boabe");
	product2.setRecipe((char*)"mult xanax");
	product2.setPrice(25);
	
	assert(product2.getCode() == 20);
	assert(strcmp(product2.getName(), "multe boabe") == 0);
	assert(strcmp(product2.getRecipe(), "mult xanax") == 0);
	assert(product2.getPrice() == 25);

	assert(!(product1 == product2));

}

//tests for the repository's functionalities and methods
//such as add,constructor,update,delete,getAll,getPosition
//in  :
//out :
void testRepository()
{
	Repo<Machine> repository;
	Machine product1(11, (char*)"boabe", (char*)"xanax", 10.5);
	Machine product2;

	product2.setCode(20);
	product2.setName((char*)"multe boabe");
	product2.setRecipe((char*)"mult xanax");
	product2.setPrice(25);

	repository.add(product1);
	repository.add(product2);

	Machine one = repository.getPosition(0);
	Machine two = repository.getPosition(1);

	assert(!(one == two));
	assert(repository.getSize() == 2);
	assert(one.getCode() == repository.getAll()[0].getCode());
	assert(two.getCode() == repository.getAll()[1].getCode());
	
	repository.remove(product1);
	
	assert(repository.getSize() == 1);
	assert(two.getCode() == repository.getAll()[0].getCode());

}

//tests for file repository's functionalities and methods
//such as add,constructor,update,delete,getAll,getPosition
//in  :
//out :
void testRepositoryFile()
{
	RepoSTL<Machine> repositoryFile("fileTest.txt");
	Machine product1(11, (char*)"boabe", (char*)"xanax", 10.5);
	Machine product2;

	product2.setCode(20);
	product2.setName((char*)"multe boabe");
	product2.setRecipe((char*)"mult xanax");
	product2.setPrice(25);

	repositoryFile.add(product1);
	repositoryFile.add(product2);

	Machine one = repositoryFile.getPosition(0);
	Machine two = repositoryFile.getPosition(1);

	assert(!(one == two));
	assert(repositoryFile.getSize() == 2);
	assert(one.getCode() == repositoryFile.getAll()[0].getCode());
	assert(two.getCode() == repositoryFile.getAll()[1].getCode());

	repositoryFile.remove(product1);

	assert(repositoryFile.getSize() == 1);
	assert(two.getCode() == repositoryFile.getAll()[0].getCode());

}

//tests for service's functionalities and methods
//such as add,constructor,update,delete,getAll,getPosition
//in  : -
//out : -
void testService() {
	char* nume1 = new char[strlen("ciocolata") + 1];
	strcpy_s(nume1, strlen("ciocolata") + 1, "ciocolata");
	char* ingredinte1 = new char[strlen("multa ciocolata") + 1];
	strcpy_s(ingredinte1, strlen("multa ciocolata") + 1, "multa ciocolata");

	char* nume2 = new char[strlen("Amandina") + 1];
	strcpy_s(nume2, strlen("Amandina") + 1, "Amandina");
	char* ingredinte2 = new char[strlen("cafeaPiscoturi") + 1];
	strcpy_s(ingredinte2, strlen("cafeaPiscoturi") + 1, "cafeaPiscoturi");

	char* nume3 = new char[strlen("tort") + 1];
	strcpy_s(nume3, strlen("tort") + 1, "tort");
	char* ingredinte3 = new char[strlen("blat ciocolata") + 1];
	strcpy_s(ingredinte3, strlen("blat ciocolata") + 1, "blat ciocolata");

	Service servicePrajituri;
	servicePrajituri.add(3, nume1, ingredinte1, 5.5);
	servicePrajituri.add(2, nume2, ingredinte2, 4.5);
	servicePrajituri.add(1, nume3, ingredinte3, 5.5);
	assert(servicePrajituri.getSize() == 3);

	assert(servicePrajituri.getAll()[0].getCode() == 3);
	assert(servicePrajituri.getAll()[1].getCode() == 2);
	assert(servicePrajituri.getAll()[2].getCode() == 1);

	servicePrajituri.removeByCode(3);

	assert(servicePrajituri.getAll()[1].getCode() == 1);

	assert(servicePrajituri.getSize() == 2);

}