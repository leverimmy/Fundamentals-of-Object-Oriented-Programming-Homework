#include "CP_Complex.h"

bool CP_Complex::operator==(const CP_Complex& rhs) const {
    return m_re == rhs.m_re && m_im == rhs.m_im;
}

CP_Complex CP_Complex::operator+(const CP_Complex& rhs) const {
    return CP_Complex(m_re + rhs.m_re, m_im + rhs.m_im);
}

CP_Complex CP_Complex::operator-(const CP_Complex& rhs) const {
    return CP_Complex(m_re - rhs.m_re, m_im - rhs.m_im);
}

CP_Complex CP_Complex::operator*(const CP_Complex& rhs) const {
    return CP_Complex(m_re * rhs.m_re - m_im * rhs.m_im, m_re * rhs.m_im + m_im * rhs.m_re);
}

CP_Complex CP_Complex::operator/(const CP_Complex& rhs) const {
    return CP_Complex((m_re * rhs.m_re + m_im * rhs.m_im) / (rhs.m_re * rhs.m_re + rhs.m_im * rhs.m_im),
                        (m_im * rhs.m_re - m_re * rhs.m_im) / (rhs.m_re * rhs.m_re + rhs.m_im * rhs.m_im));
}

CP_Complex CP_Complex::operator++() {
    m_re++;
    return *this;
}

CP_Complex CP_Complex::operator++(int) {
    CP_Complex temp = *this;
    m_re++;
    return temp;
}

CP_Complex CP_Complex::operator--() {
    m_re--;
    return *this;
}

CP_Complex CP_Complex::operator--(int) {
    CP_Complex temp = *this;
    m_re--;
    return temp;
}

ostream& operator<<(ostream& os, const CP_Complex& c) {
    os << c.m_re << " + " << c.m_im << "i";
    return os;
}

istream& operator>>(istream& is, CP_Complex& c) {
    is >> c.m_re >> c.m_im;
    return is;
}