#ifndef CP_CIRCLE_H
#define CP_CIRCLE_H

#include "CP_Point.h"

class CP_Circle {
public:
	CP_Point m_center;
	double m_radius;
public:
	CP_Circle(CP_Point c, double r = 0.0);
	CP_Circle(const CP_Circle& p);
};
#endif
