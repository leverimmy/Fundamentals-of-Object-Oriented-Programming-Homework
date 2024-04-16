#include "pch.h"
#include "CP_Circle.h"

CP_Circle::CP_Circle(CP_Point c, double r) : m_center(c), m_radius(r) {

}

CP_Circle::CP_Circle(const CP_Circle& p) : m_center(p.m_center), m_radius(p.m_radius) {

}
