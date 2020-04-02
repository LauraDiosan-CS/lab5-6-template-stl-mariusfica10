#include "Tests.h"
#include "Repository.h"
#include "Machine.h"
#include <iostream>
using namespace std;


/*
//desc: main function
in: -
out: 0
*/
int main()
{
    testDomain();
    testRepository();

    cout << "all tests are correct!"<<endl;
    cout << "exit" << endl;
    return 0;
}
