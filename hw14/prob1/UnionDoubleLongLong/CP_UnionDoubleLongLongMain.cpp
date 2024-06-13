#include <iostream>
using namespace std;
#include "CP_UnionDoubleLongLong.h"

int main(int argc, char* args[]) {
    double d = 0.0;
    cin >> d;
    U_DoubleLongLong u(d);
    gb_showDoubleLongLongHexMemory(u);
    gb_testDoubleLongLong();
    system("pause");
    return 0;
}
