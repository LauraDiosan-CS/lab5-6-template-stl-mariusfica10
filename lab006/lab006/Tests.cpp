#include "Tests.h"
#include "Repository.cpp"
#include "Machine.h"
#include <assert.h>

//test for repository
void testRepository()
{
	Machine a1(10, (char*)"praji", (char*)"tura", 10);


	Repository <Machine> repo;

	repo.addElem(a1);

	Machine* elem = repo.getAll();

	assert(elem[0] == a1);
	cout << "repository tests are good" << endl;

	Machine a2 = a1;

	repo.addElem(a2);
	Machine* elems = repo.getAll();
	assert(elems[1] == a1);
}

//test for machine class
void testDomain()
{

	

	Machine a1(10, (char*)"da",(char*) "da", 10);
	Machine a2;

	

	assert(a1.getCode() == 10);
	assert(a1.getPrice() == 10);

	assert(strcmp(a1.getName(),"da") == 0);
	assert(strcmp(a1.getRecipe(),"da") == 0);

	a1.setCode(20);
	a1.setPrice(20);
	assert(a1.getCode() == 20);
	assert(a1.getPrice() == 20);

	assert(strcmp(a1.getName(),(char *) "da") == 0);
	assert(strcmp(a1.getRecipe(),(char *) "da") == 0);
	
	cout << "domain tests are good" << endl;

	/*
	a1.setCode(20);
	a1.setPrice(20);
	assert(a1.getCode()== 20);
	assert(a1.getPrice() == 20);
	*/
}