#include <iostream>
#include <cassert>
using namespace std;
#include "CP_Shape.h"

int main (int argc, char* args[]) {
    
    int opt;
    int sum_num = 0;
    double sum_circumference = 0;
    double sum_area = 0;

    while (cin >> opt) {
        if (opt == 0) {
            cout << sum_num << " " << sum_circumference << " " << sum_area << endl;
            continue;
        }

        double side_length = 0;
        cin >> side_length;

        CP_Shape *current_shape = nullptr;
        switch (opt) {
            case 1:
                current_shape = new CP_Triangle(side_length);
                break;
            case 2:
                current_shape = new CP_Square(side_length); 
                break;
            case 3:
                current_shape = new CP_Pentagon(side_length); 
                break;
            case 4:
                current_shape = new CP_Hexagon(side_length); 
                break;
            case 5:
                current_shape = new CP_Circle(side_length); 
                break;
            default:
                break;
        }
        sum_num++;
        sum_circumference += current_shape->calc_circumference();
        sum_area += current_shape->calc_area();

        cout << current_shape->calc_circumference() << " " << current_shape->calc_area() << endl;
    }

    system("pause");
    return 0;
}