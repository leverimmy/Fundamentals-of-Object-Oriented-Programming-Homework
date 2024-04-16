#ifndef CP_POINT_H
#define CP_POINT_H

class CP_Point {
public:
	double m_x, m_y;
public:
	CP_Point(double x = 0.0, double y = 0.0);
	CP_Point(const CP_Point& p);
};
#endif
