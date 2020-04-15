#include <iostream>
#include "Tests.h"
#include "Repository.h"
#include "RepositoryFile.h"
#include "RepoTemplate.h"
#include "Service.h"
#include "UI.h"
//#include"UI.h"
using namespace std;

int main()
{
    cout << "testing....." << '\n';
    testDomain();
    testRepository();
    testRepoFile();
    testService();
    cout << "everything looks good :)" << '\n' << '\n';

    RepositoryFile<Entity> repository("Parcare.txt");
    Service service(repository);
    ////service.addObject("Raluca", "CJ76RRR", "liber");
    ////service.addObject("Dragos", "NT34DDD", "ocupat");
    ////service.addObject("Iulia", "NT12RRR", "ocupat");
    ////service.addObject("Robert", "B46MMM", "liber");
    UI user(service);
    user.console();
    return 0;
}
