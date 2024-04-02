#include <iostream>
#include <cassert>
using namespace std;
#include "CP_StudentManagementSystem.h"

int main(int argc, char* args[]) {
    CP_StudentManagementSystem my_system;
    
    while (true) {
        int command, id, score;
        cout << "Enter command (1: Add, 2: Delete by ID, 3: Delete by Score, 4: Show score by ID, 5: Show ID by Score, 6: Show all students, -1: Exit): " << endl;
        cin >> command;
        if (command == -1) {
            break;
        }
        switch (command) {
            case 1:
                cout << "Enter student ID and score (terminate with 0): " << endl;
                cin >> id;
                while (id != 0) {
                    cin >> score;
                    my_system.addStudent(id, score);
                    cin >> id;
                }
                break;
            case 2:
                cout << "Enter student ID to delete: " << endl;
                cin >> id;
                my_system.deleteStudentById(id);
                break;
            case 3:
                cout << "Enter student score to delete: " << endl;
                cin >> score;
                my_system.deleteStudentByScore(score);
                break;
            case 4:
                cout << "Enter student ID to show score: " << endl;
                cin >> id;
                my_system.showStudentScore(id);
                break;
            case 5:
                cout << "Enter student score to show IDs: " << endl;
                cin >> score;
                my_system.showStudentIdByScore(score);
                cout << endl;
                break;
            case 6:
                my_system.showAllStudents();
                cout << endl;
                break;
            default:
                cout << "Invalid command." << endl;
                break;
        }
    }
    system("pause");
    return 0;
}
