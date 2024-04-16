#ifndef CP_TRIANGLE_H
#define CP_TRIANGLE_H

#include "CP_Point.h"

class CP_Triangle {
public:
	CP_Point m_center;
	double m_side_length;
public:
	CP_Triangle(CP_Point c, double l = 0.0);
	CP_Triangle(const CP_Triangle& p);
	virtual ~CP_Triangle() {};
};
#endif
