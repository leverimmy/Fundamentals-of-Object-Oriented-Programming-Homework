#include <iostream>
#include <cassert>
#include "CP_StudentManagementSystem.h"

int main(int argc, char* args[]) {
    CP_StudentManagementSystem my_system;

    // Add students
    my_system.addStudent(101, 85);
    my_system.addStudent(102, 80);
    my_system.addStudent(104, 80);
    my_system.addStudent(105, 80);
    my_system.addStudent(106, 80);
    my_system.addStudent(103, 75);

    // Get all student information
    assert(my_system.getAllStudents().size() == 6); // There should be 6 students in total
    assert(my_system.getStudentScore(101) == 85); // Score of student with ID 101 should be 85
    assert(my_system.getStudentScore(102) == 80); // Score of student with ID 102 should be 80
    assert(my_system.getStudentScore(103) == 75); // Score of student with ID 103 should be 75
    assert(my_system.getStudentScore(104) == 80); // Score of student with ID 104 should be 80
    assert(my_system.getStudentScore(105) == 80); // Score of student with ID 105 should be 80
    assert(my_system.getStudentScore(106) == 80); // Score of student with ID 106 should be 80

    // Delete students
    assert(my_system.getStudentScore(102) == 80); // Score of student with ID 102 should be 80
    my_system.deleteStudentById(102);
    assert(my_system.getStudentScore(102) == -1); // Ensure student has been deleted

    assert(my_system.getStudentScore(103) == 75); // Score of student with ID 103 should be 75
    my_system.deleteStudentByScore(75);
    assert(my_system.getStudentScore(103) == -1); // Ensure student with score 75 has been deleted

    // Get student scores
    assert(my_system.getStudentScore(101) == 85); // Score of student with ID 101 should be 85
    assert(my_system.getStudentScore(102) == -1); // Score of deleted student should be -1

    // Get student IDs with specified score
    vector<int> studentsWithScore80 = my_system.getStudentIdByScore(80);
    assert(studentsWithScore80.size() == 3); // There should be 3 students with score 80
    assert(studentsWithScore80[0] == 104); // First student ID with score 80 should be 104
    assert(studentsWithScore80[1] == 105); // Second student ID with score 80 should be 105
    assert(studentsWithScore80[2] == 106); // Third student ID with score 80 should be 106

    // Clear all student information
    my_system.clearAllStudents();
    assert(my_system.getAllStudents().empty()); // Student list should be empty

    // All tests passed
    cout << "All tests passed!" << endl;
    return 0;
}
