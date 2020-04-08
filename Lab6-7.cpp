#include <iostream>
#include "TestDomain.h"
#include "TestRepository.h"
#include "TestService.h"
#include "Repository.h"
#include "Service.h"
#include"UI.h"
using namespace std;

int main()
{
    cout << "testing....."<<'\n';
    testDomain();
    testRepository();
    //testService();
    cout << "everything looks good :)"<<'\n'<<'\n';

    RepositoryFile repository("Parcare2.txt");
    Service service(repository);
    //service.addObject("Raluca", "CJ76RRR", "liber");
    //service.addObject("Dragos", "NT34DDD", "ocupat");
    //service.addObject("Iulia", "NT12RRR", "ocupat");
    //service.addObject("Robert", "B46MMM", "liber");
    UI user(service);
    user.console();
    return 0;
}
