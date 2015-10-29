#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

main()
{
    //variables
    string sDirectory;

    cout << "Executing APP:GitPushFolder" << endl;
    cout << "Please enter a directory" << endl;
    cin >> sDirectory;
    cin.get();
    chdir(sDirectory.c_str());

    cout << "   APP:GitPushFolder > Add" << endl;
    system("git add .");
    cout << "   APP:GitPushFolder > Commit as LastCommit" << endl;
    system("git commit -m 'LastCommit'");
    cout << "   APP:GitPushFolder > Push to master" << endl;
    system("git push origin master");
    return 0;
}
