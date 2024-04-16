#include "pch.h"
#include "CP_Triangle.h"

CP_Triangle::CP_Triangle(CP_Point a, CP_Point b, CP_Point c) : m_a(a), m_b(b), m_c(c) {

}

CP_Triangle::CP_Triangle(const CP_Triangle& p) : m_a(p.m_a), m_b(p.m_b), m_c(p.m_c) {

}
