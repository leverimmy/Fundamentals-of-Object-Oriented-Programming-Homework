#include <iostream>
using namespace std;
#include "CP_GCDLCM.h"

int CP_GCDLCM::gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

long long CP_GCDLCM::lcm(int x, int y) {
    return (long long)x * y / gcd(x, y);
}
