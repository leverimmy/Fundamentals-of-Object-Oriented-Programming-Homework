#include <iostream>
#include <cassert>
using namespace std;
#include "CP_Date.h"

int main (int argc, char* args[]) {
    
    CP_Date currentDate = CP_Date(2024, 3, 19);

    int delta_days;
    cin >> delta_days;
    cout << "Year: " << currentDate.query(delta_days).getYear() << endl
        << "Month: " << currentDate.query(delta_days).getMonth() << endl
        << "Day: " << currentDate.query(delta_days).getDay() << endl;

    system("pause");
    return 0;
}