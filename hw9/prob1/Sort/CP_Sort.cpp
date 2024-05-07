#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#include "CP_Sort.h"

void CP_Sort::sort() {
    std::sort(m_arr.begin(), m_arr.end());
}

void CP_Sort::sort_and_deduplicate() {
    set<int> s(m_arr.begin(), m_arr.end());
    m_arr.assign(s.begin(), s.end());
}

vector<int> CP_Sort::get() {
    return m_arr;
}

void CP_Sort::print() {
    cout << "[";
    for (int i = 0; i < m_arr.size(); i++) {
        if (i + 1 < m_arr.size())
            cout << m_arr[i] << ", ";
        else
            cout << m_arr[i];
    }
    cout << "]" << endl;
}