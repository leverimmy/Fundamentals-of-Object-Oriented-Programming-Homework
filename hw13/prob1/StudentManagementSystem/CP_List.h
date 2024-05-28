#ifndef CP_LIST_H
#define CP_LIST_H

#include "CP_Student.h"
#include <vector>
#include <iostream>
using namespace std;

class CP_List {
private:
    CP_Student* head;
    CP_Student* tail;
public:
    CP_List();
    CP_Student* front();
    void push_back(CP_Student* student);
    void pop_front();
    void pop_back();
    bool empty();
};
#endif
