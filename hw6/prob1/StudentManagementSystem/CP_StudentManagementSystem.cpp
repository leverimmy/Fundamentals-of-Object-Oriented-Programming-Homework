#include "CP_StudentManagementSystem.h"

CP_StudentManagementSystem::CP_StudentManagementSystem() : head(nullptr), tail(nullptr) {}

void CP_StudentManagementSystem::addStudent(int id, int score) {
    CP_Student* newStudent = new CP_Student(id, score);
    if (!head) {
        head = tail = newStudent;
    } else {
        CP_Student* current = head;
        while (current && current->id < id) {
            current = current->next;
        }
        if (!current) {
            tail->next = newStudent;
            newStudent->prev = tail;
            tail = newStudent;
        } else {
            if (current->prev) {
                current->prev->next = newStudent;
            } else {
                head = newStudent;
            }
            newStudent->prev = current->prev;
            newStudent->next = current;
            current->prev = newStudent;
        }
    }
}

void CP_StudentManagementSystem::deleteStudentById(int id) {
    CP_Student* current = head;
    while (current && current->id != id) {
        current = current->next;
    }
    if (!current) {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }
    delete current;
    cout << "Student with ID " << id << " deleted." << endl;
}

void CP_StudentManagementSystem::deleteStudentByScore(int score) {
    CP_Student* current = head;
    while (current) {
        if (current->score == score) {
            CP_Student* temp = current;
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            current = current->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    cout << "Students with score " << score << " deleted." << endl;
}

int CP_StudentManagementSystem::getStudentScore(int id) {
    CP_Student* current = head;
    while (current && current->id != id) {
        current = current->next;
    }
    return current ? current->score : -1;
}

void CP_StudentManagementSystem::showStudentScore(int id) {
    int result = getStudentScore(id);
    if (~result) {
        cout << "Student with ID " << id << " has score " << result << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

vector<int> CP_StudentManagementSystem::getStudentIdByScore(int score) {
    vector<int> result;
    CP_Student* current = head;
    while (current) {
        if (current->score == score) {
            result.push_back(current->id);
        }
        current = current->next;
    }
    return result;
}

void CP_StudentManagementSystem::showStudentIdByScore(int score) {
    vector<int> result = getStudentIdByScore(score);
    if (result.empty()) {
        cout << "No student found with score " << score;
    } else {
        cout << "Students with score " << score << ": ";
        for (auto student_id : result) {
            cout << student_id << " ";
        }
    }
}

vector<int> CP_StudentManagementSystem::getAllStudents() {
    vector<int> result;
    CP_Student* current = head;
    while (current) {
        result.push_back(current->id);
        current = current->next;
    }
    return result;
}

void CP_StudentManagementSystem::showAllStudents() {
    vector<int> result = getAllStudents();
    if (result.empty()) {
        cout << "No student found." << endl;
    } else {
        cout << "All students: ";
        for (auto student_id : result) {
            cout << student_id << " ";
        }
    }
}

void CP_StudentManagementSystem::clearAllStudents() {
    CP_Student* current = head;
    while (current) {
        CP_Student* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    cout << "All students cleared." << endl;
}
