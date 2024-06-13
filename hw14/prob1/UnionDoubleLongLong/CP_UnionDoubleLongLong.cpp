#include <iostream>
#include <iomanip>
using namespace std;
#include "CP_UnionDoubleLongLong.h"

void gb_showDoubleLongLongHexMemory(const U_DoubleLongLong & u) {
    cout << u.m_double;
    cout << " is stored as ";
    cout << setbase(2) << u.m_long_long << "." << endl << dec;
}

void gb_testDoubleLongLong() {
    U_DoubleLongLong u(0.0f);
    u.m_double = 0.0f / u.m_double; // 得到非数
    gb_showDoubleLongLongHexMemory(u);
}
