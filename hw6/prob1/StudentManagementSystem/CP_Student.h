#ifndef CP_STUDENT_H
#define CP_STUDENT_H

class CP_Student {
public:
    int id;
    int score;
    CP_Student* prev;
    CP_Student* next;
    CP_Student(int _id, int _score) : id(_id), score(_score), prev(nullptr), next(nullptr) {}
};
#endif