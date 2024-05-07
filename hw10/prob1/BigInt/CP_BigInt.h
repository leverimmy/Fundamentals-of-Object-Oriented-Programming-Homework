#include <iostream>
#include <string>
#include <vector>
using namespace std;
#ifndef CP_BIGINT_H
#define CP_BIGINT_H

class CP_BigInt {
public:
    CP_BigInt() : m_sign(true) { m_data.clear(); }
    CP_BigInt(const vector<int>& data, bool flag = true) : m_sign(flag), m_data(data) {}
    CP_BigInt(const string& data) { setValue(data); }

    bool getSign() const { return m_sign; }
    vector<int> getData() const { return m_data; }
    void setValue(const string& data);
    string toString() const;

    CP_BigInt operator-() const;
    CP_BigInt operator+(const CP_BigInt& rhs) const;
    CP_BigInt operator-(const CP_BigInt& rhs) const;
    CP_BigInt operator=(const CP_BigInt& rhs);
    bool operator==(const CP_BigInt& rhs) const;
    bool operator>(const CP_BigInt& rhs) const;
    friend ostream& operator<<(ostream& os, const CP_BigInt& rhs);
    friend istream& operator>>(istream& is, CP_BigInt& rhs);

private:
    bool m_sign; // true 表示非负数，false 表示负数
    vector<int> m_data; // 全部元素由 0~9 组成，而且不以 0 开头。m_data.length == 0 表示 0
};
#endif
