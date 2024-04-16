#include "pch.h"
#include "CP_Triangle.h"

CP_Triangle::CP_Triangle(CP_Point c, double l) : m_center(c), m_side_length(l) {

}

CP_Triangle::CP_Triangle(const CP_Triangle& p) : m_center(p.m_center), m_side_length(p.m_side_length) {

}
