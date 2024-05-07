#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "CP_BigInt.h"

void CP_BigInt::setValue(const string& data) {
    // st 表示符号后从左往右数第一个非 0 的位置
    int len = data.length(), st = 0;
    try {
        if (len == 0) {
            throw invalid_argument("Invalid data format");
        } else if (data[0] == '+' || data[0] == '-') {
            if (data.length() == 1) {
                throw invalid_argument("Invalid data format");
            } else {
                for (int i = 1; i < data.length(); i++) {
                    if (data[i] < '0' || data[i] > '9') {
                        throw invalid_argument("Invalid data format");
                    }
                }
            }
            st = 1;
        } else {
            for (int i = 0; i < data.length(); i++) {
                if (data[i] < '0' || data[i] > '9') {
                    throw invalid_argument("Invalid data format");
                }
            }
        }

        // 初始化
        m_data.clear();
        m_sign = st == 1 ? data[0] == '+' : true;

        // 去除前导 0
        while (data[st] == '0') {
            st++;
        }
        // 如果全是前导 0，说明是 0
        if (st == len) {
            m_sign = 1;
        } else {
            for (int i = len - 1; i >= st; i--) {
                m_data.push_back(data[i] - '0');
            }
        }
    } catch (invalid_argument& e) {
        m_data.clear();
        m_sign = true;
        cout << e.what() << endl;
    }
}

string CP_BigInt::toString() const {
    string result;
    if (m_data.size() == 0) {
        result = "0";
    } else {
        result = m_sign ? "" : "-";
        for (int i = m_data.size() - 1; i >= 0; i--) {
            result += m_data[i] + '0';
        }
    }
    return result;
}

CP_BigInt CP_BigInt::operator-() const {
    CP_BigInt result = *this;
    result.m_sign = !result.m_sign;
    return result;
}

CP_BigInt CP_BigInt::operator+(const CP_BigInt& rhs) const {
    CP_BigInt result;
    if (rhs.m_sign == m_sign) {
        // 同号相加
        CP_BigInt augend = *this > rhs ? *this : rhs; // 被加数
        CP_BigInt addend = rhs > *this ? *this : rhs; // 加数

        result.m_sign = augend.m_sign;
        // 补齐位数
        while (addend.m_data.size() < augend.m_data.size()) {
            addend.m_data.push_back(0);
        }

        int carry = 0;
        for (int i = 0; i < augend.m_data.size(); i++) {
            result.m_data.push_back((augend.m_data[i] + addend.m_data[i] + carry) % 10);
            carry = (augend.m_data[i] + addend.m_data[i] + carry) / 10;
        }
        if (carry > 0) {
            result.m_data.push_back(carry);
        }
    } else {
        // 异号相加
        CP_BigInt minuend = m_sign ? *this : rhs; // 被减数
        CP_BigInt subtrahend = m_sign ? -rhs : -(*this); // 减数

        // 如果被减数大于减数，则结果非负，否则结果为负
        if (minuend > subtrahend) {
            result.m_sign = true;
        } else {
            result.m_sign = false;
            swap(minuend, subtrahend);
        }
        // 补齐位数
        while (subtrahend.m_data.size() < minuend.m_data.size()) {
            subtrahend.m_data.push_back(0);
        }

        int borrow = 0;
        for (int i = 0; i < minuend.m_data.size(); i++) {
            int sub = minuend.m_data[i] - subtrahend.m_data[i] - borrow;
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.m_data.push_back(sub);
        }

        while (result.m_data.size() > 0 && result.m_data.back() == 0) {
            result.m_data.pop_back();
        }
        if (result.m_data.size() == 0) {
            result.m_sign = true;
        }
    }
    return result;
}

CP_BigInt CP_BigInt::operator-(const CP_BigInt& rhs) const {
    return *this + (-rhs);
}

CP_BigInt CP_BigInt::operator=(const CP_BigInt& rhs) {
    m_sign = rhs.m_sign;
    m_data = rhs.m_data;
    return *this;
}

bool CP_BigInt::operator==(const CP_BigInt& rhs) const {
    return m_data == rhs.m_data && m_sign == rhs.m_sign;
}

bool CP_BigInt::operator>(const CP_BigInt& rhs) const {
    if (m_sign && !rhs.m_sign) {
        return true;
    } else if (!m_sign && rhs.m_sign) {
        return false;
    } else if (m_sign && rhs.m_sign) {
        if (m_data.size() > rhs.m_data.size()) {
            return true;
        } else if (m_data.size() < rhs.m_data.size()) {
            return false;
        } else {
            for (int i = m_data.size() - 1; i >= 0; i--) {
                if (m_data[i] > rhs.m_data[i]) {
                    return true;
                } else if (m_data[i] < rhs.m_data[i]) {
                    return false;
                }
            }
            return false;
        }
    } else {
        return -rhs > -(*this);
    }
}

ostream& operator<<(ostream& os, const CP_BigInt& rhs) {
    os << rhs.toString();
    return os;
}

istream& operator>>(istream& is, CP_BigInt& rhs) {
    string str;
    is >> str;
    rhs.setValue(str);
    return is;
}
