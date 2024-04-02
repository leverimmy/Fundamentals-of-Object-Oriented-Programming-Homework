#include <iostream>
#include <cassert>
using namespace std;
#include "CP_Complex.h"

int main(int argc, char* args[]) {

    CP_Complex a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << "a = " << a << "b = " << b << endl;
    cout << "c = " << c << "d = " << d << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "c * d = " << c * d << endl;
    cout << "c / d = " << c / d << endl;
    cout << "a++ = " << a++ << endl;
    cout << "++b = " << ++b << endl;
    cout << "c-- = " << c-- << endl;
    cout << "--d = " << --d << endl;

    assert(CP_Complex(1, 2) + CP_Complex(3, 4) == CP_Complex(4, 6));
    assert(CP_Complex(0, 2) - CP_Complex(3, 4) == CP_Complex(-3, -2));
    assert(CP_Complex(1, 0) * CP_Complex(3, 4) == CP_Complex(3, 4));
    assert(CP_Complex(2, 4) / CP_Complex(0, 2) == CP_Complex(2, -1));

    CP_Complex t1, t2, t3, t4;
    t1 = t2 = t3 = t4 = CP_Complex(1, 2);
    assert(t1++ == CP_Complex(1, 2));
    assert(++t2 == CP_Complex(2, 2));
    assert(t3-- == CP_Complex(1, 2));
    assert(--t4 == CP_Complex(0, 2));

    system("pause");
    return 0;
}