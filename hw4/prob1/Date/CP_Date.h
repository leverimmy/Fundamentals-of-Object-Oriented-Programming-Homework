#ifndef CP_DATE_H
#define CP_DATE_H

class CP_Date {
public:
    CP_Date(int year, int month, int day): m_year(year), m_month(month), m_day(day) {}
    virtual ~CP_Date() {}

    CP_Date query(int d);
    int getYear();
    int getMonth();
    int getDay();

private:
    int m_year;
    int m_month;
    int m_day;
};
#endif
