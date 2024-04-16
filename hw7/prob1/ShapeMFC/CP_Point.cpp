#include "pch.h"
#include "CP_Point.h"

CP_Point::CP_Point(double x, double y) : m_x(x), m_y(y) {

}

CP_Point::CP_Point(const CP_Point& p) : m_x(p.m_x), m_y(p.m_y) {

}
