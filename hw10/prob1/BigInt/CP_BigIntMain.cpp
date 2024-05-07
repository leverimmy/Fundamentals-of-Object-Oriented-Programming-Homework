#include <iostream>
#include <string>
using namespace std;
#include "CP_BigInt.h"

int main(int argc, char* args[]) {

    CP_BigInt a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    system("pause");
    return 0;
}
