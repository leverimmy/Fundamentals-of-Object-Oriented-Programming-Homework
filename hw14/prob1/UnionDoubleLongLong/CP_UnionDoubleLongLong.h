#ifndef CP_UNIONDOUBLELONGLONG_H
#define CP_UNIONDOUBLELONGLONG_H

union U_DoubleLongLong {
    double m_double;
    long long m_long_long;
    U_DoubleLongLong(long long ll = 0) : m_long_long(ll) {}
    U_DoubleLongLong(double d) : m_double(d) {}
    U_DoubleLongLong(const U_DoubleLongLong & u) : m_long_long(u.m_long_long) {}
    ~U_DoubleLongLong() {}
};

extern void gb_showDoubleLongLongHexMemory(const U_DoubleLongLong & u);
extern void gb_testDoubleLongLong();
#endif
