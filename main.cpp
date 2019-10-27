#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include "AlgoSort.h"

using namespace std;
int main(int argc, char *argv[]) {
    vector<string> arguments(argv + 1, argv + argc);
    AlgoSort a(arguments);
    clock_t t;
    t = clock();
    a.sort();
    t = clock() - t;
    cout << "It took " << t << " clicks(" << ((float)t) / CLOCKS_PER_SEC << "seconds)\n";

    a.write();
    return 0;
}