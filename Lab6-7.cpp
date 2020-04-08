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
    testService();
    cout << "everything looks good :)"<<'\n'<<'\n';

    Repository repository;
    Service service(repository);
    service.addObject("Raluca Mitrea", "CJ76RRR", "liber");
    service.addObject("Dragos Radu", "NT34DDD", "ocupat");
    service.addObject("Iulia Rotaru", "NT12RRR", "ocupat");
    service.addObject("Robert Mancas", "B46MMM", "liber");
    UI user(service);
    user.console();
    return 0;
}
