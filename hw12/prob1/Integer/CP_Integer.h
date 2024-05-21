#include <iostream>
#include <string>
#include "CP_Exception.h"
using namespace std;
#ifndef CP_INTEGER_H
#define CP_INTEGER_H

class CP_Integer {
public:
    CP_Integer(const string &s);
    friend ostream &operator<<(ostream &os, const CP_Integer &cp);
    int get_x() const;
    CP_Exception_Base *get_exception() const;
private:
    int m_x;
    CP_Exception_Base *m_exception;
};
#endif
