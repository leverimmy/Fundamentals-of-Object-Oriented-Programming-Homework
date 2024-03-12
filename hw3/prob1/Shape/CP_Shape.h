#ifndef CP_SHAPE_H
#define CP_SHAPE_H

class CP_Shape {
public:
    CP_Shape(double side_length = 0): m_side_length(side_length) {}
    virtual ~CP_Shape() {}
    
    virtual double calc_circumference() = 0;
    virtual double calc_area() = 0;

protected:
    double m_side_length;
};

class CP_Triangle : public CP_Shape {
public:
    CP_Triangle(double side_length = 0);
    double calc_circumference();
    double calc_area();
};

class CP_Square : public CP_Shape {
public:
    CP_Square(double side_length = 0);
    double calc_circumference();
    double calc_area();
};

class CP_Pentagon : public CP_Shape {
public:
    CP_Pentagon(double side_length = 0);
    double calc_circumference();
    double calc_area();
};

class CP_Hexagon : public CP_Shape {
public:
    CP_Hexagon(double side_length = 0);
    double calc_circumference();
    double calc_area();
};

class CP_Circle : public CP_Shape {
public:
    CP_Circle(double side_length = 0);
    double calc_circumference();
    double calc_area();
};
#endif