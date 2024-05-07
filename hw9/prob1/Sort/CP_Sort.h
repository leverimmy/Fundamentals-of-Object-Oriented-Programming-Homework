#include <vector>
using namespace std;
#ifndef CP_SORT_H
#define CP_SORT_H

class CP_Sort {
public:
    CP_Sort(vector<int> arr): m_arr(arr) {}
    CP_Sort() { m_arr = vector<int>(); }
    virtual ~CP_Sort() {}

    void sort();
    void sort_and_deduplicate();
    vector<int> get();
    void print();

private:
    vector<int> m_arr;
};
#endif