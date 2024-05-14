#include "CP_Shape.h"

CP_Triangle::CP_Triangle(double side_length) {
    m_side_length = side_length;
}

double CP_Triangle::calc_circumference() {
    return 3.0 * m_side_length;
}

double CP_Triangle::calc_area() {
    return sqrt(3) / 4 * m_side_length * m_side_length;
}

CP_Square::CP_Square(double side_length) {
    m_side_length = side_length;
}

double CP_Square::calc_circumference() {
    return 4.0 * m_side_length;
}

double CP_Square::calc_area() {
    return m_side_length * m_side_length;
}

CP_Pentagon::CP_Pentagon(double side_length) {
    m_side_length = side_length;
}

double CP_Pentagon::calc_circumference() {
    return 5.0 * m_side_length;
}

double CP_Pentagon::calc_area() {
    return sqrt(25 + 10 * sqrt(5)) / 4 * m_side_length * m_side_length;
}

CP_Hexagon::CP_Hexagon(double side_length) {
    m_side_length = side_length;
}

double CP_Hexagon::calc_circumference() {
    return 6.0 * m_side_length;
}

double CP_Hexagon::calc_area() {
    return 3.0 * sqrt(3) / 2 * m_side_length * m_side_length;
}

CP_Circle::CP_Circle(double side_length) {
    m_side_length = side_length;
}

double CP_Circle::calc_circumference() {
    return 2.0 * M_PI * m_side_length;
}

double CP_Circle::calc_area() {
    return M_PI * m_side_length * m_side_length;
}
