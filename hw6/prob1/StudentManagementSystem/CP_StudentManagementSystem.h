#ifndef CP_STUDENTMANAGEMENTSYSTEM_H
#define CP_STUDENTMANAGEMENTSYSTEM_H

#include "CP_Student.h"
#include <vector>
#include <iostream>
using namespace std;

class CP_StudentManagementSystem {
private:
    CP_Student* head;
    CP_Student* tail;
public:
    CP_StudentManagementSystem();
    void addStudent(int id, int score);
    void deleteStudentById(int id);
    void deleteStudentByScore(int score);
    int getStudentScore(int id);
    void showStudentScore(int id);
    vector<int> getStudentIdByScore(int score);
    void showStudentIdByScore(int score);
    vector<int> getAllStudents();
    void showAllStudents();
    void clearAllStudents();
};
#endif
