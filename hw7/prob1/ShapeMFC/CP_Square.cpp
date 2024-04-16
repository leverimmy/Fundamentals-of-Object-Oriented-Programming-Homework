#include "pch.h"
#include "CP_Square.h"

CP_Square::CP_Square(CP_Point c, double l) : m_center(c), m_side_length(l) {

}

CP_Square::CP_Square(const CP_Square& p) : m_center(p.m_center), m_side_length(p.m_side_length) {

}
