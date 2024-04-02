#include <iostream>
#include <cassert>
using namespace std;
#include "CP_GCDLCM.h"

int main(int argc, char* args[]) {
    CP_GCDLCM solver;
    int x, y;
    cin >> x >> y;
    cout << solver.gcd(x, y) << endl;
    cout << solver.lcm(x, y) << endl;

    assert(solver.gcd(1, 1001) == 1);
    assert(solver.gcd(1000000007, 1000000009) == 1);
    assert(solver.gcd(40000, 40000) == 40000);
    assert(solver.gcd(4551, 147723) == 123);
    assert(solver.gcd(124634, 460282) == 1234);

    assert(solver.lcm(1, 1001) == 1001);
    assert(solver.lcm(1000000007, 1000000009) == 1000000016000000063LL);
    assert(solver.lcm(40000, 40000) == 40000);
    assert(solver.lcm(4551, 147723) == 5465751);
    assert(solver.lcm(124634, 460282) == 46488482);

    system("pause");
    return 0;
}