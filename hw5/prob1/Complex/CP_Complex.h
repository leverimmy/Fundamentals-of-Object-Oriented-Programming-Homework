#include <iostream>
using namespace std;
#ifndef CP_COMPLEX_H
#define CP_COMPLEX_H

class CP_Complex {
public:
    CP_Complex(double re = 0, double im = 0): m_re(re), m_im(im) {}
    virtual ~CP_Complex() {}

    void setRe(double re) { m_re = re; }
    void setIm(double im) { m_im = im; }
    double getRe() const { return m_re; }
    double getIm() const { return m_im; }

    bool operator==(const CP_Complex& rhs) const;
    CP_Complex operator+(const CP_Complex& rhs) const;
    CP_Complex operator-(const CP_Complex& rhs) const;
    CP_Complex operator*(const CP_Complex& rhs) const;
    CP_Complex operator/(const CP_Complex& rhs) const;
    CP_Complex operator++();
    CP_Complex operator++(int);
    CP_Complex operator--();
    CP_Complex operator--(int);

    // 重载输入输出运算符，方便输入输出
    friend ostream& operator<<(ostream& os, const CP_Complex& c);
    friend istream& operator>>(istream& is, CP_Complex& c);

private:
    double m_re;
    double m_im;
};
#endif