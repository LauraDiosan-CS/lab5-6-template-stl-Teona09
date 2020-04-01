#include <iostream>
#include "TestDomain.h"
#include "TestRepository.h"
using namespace std;

int main()
{
    cout << "testing....."<<'\n';
    testDomain();
    testRepository();
    //testService();
    cout << "everything looks good :)"<<'\n'<<'\n';
    return 0;
}
