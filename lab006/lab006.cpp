#include "Tests.h"
#include "RepoSTL.h"
#include "Machine.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
using namespace std;

//desc: calls tests functions for app
//in  : -
//out : -
void verifyApp()
{
    testDomain();
    testRepository();
    testRepositoryFile();
    testService();
}

//desc: app coordinator
//  in: -
// out: -
int main()
{
    verifyApp();
    RepoSTL<Machine> repoSTL("mainShop.txt");
    Service service(repoSTL);
    UI ui(service);
    ui.runUI();


    return 0;
}
