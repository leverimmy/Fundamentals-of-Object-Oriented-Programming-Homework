#ifndef CP_TRIANGLE_H
#define CP_TRIANGLE_H

#include "CP_Point.h"

class CP_Triangle {
public:
	CP_Point m_a, m_b, m_c;
public:
	CP_Triangle(CP_Point a, CP_Point b, CP_Point c);
	CP_Triangle(const CP_Triangle& p);
	virtual ~CP_Triangle() {};
};
#endif
