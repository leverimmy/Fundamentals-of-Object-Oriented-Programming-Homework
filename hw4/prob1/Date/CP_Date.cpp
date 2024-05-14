#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
#include "CP_Date.h"

CP_Date CP_Date::query(int d) {
    int days = m_day + d;
    int month = m_month;
    int year = m_year;
    while (days > 0) {
        int month_days = 0;
        if (month == 2) {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                month_days = 29;
            } else {
                month_days = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            month_days = 30;
        } else {
            month_days = 31;
        }
        assert(month_days != 0);
        if (days > month_days) {
            days -= month_days;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        } else {
            break;
        }
    }
    return CP_Date(year, month, days);
}

int CP_Date::getYear() {
    return m_year;
}

int CP_Date::getMonth() {
    return m_month;
}

int CP_Date::getDay() {
    return m_day;
}
