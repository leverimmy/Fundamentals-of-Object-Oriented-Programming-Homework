#ifndef CP_SQUARE_H
#define CP_SQUARE_H

#include "CP_Point.h"

class CP_Square {
public:
	CP_Point m_center;
	double m_side_length;
public:
	CP_Square(CP_Point c, double l = 0.0);
	CP_Square(const CP_Square& p);
};
#endif
