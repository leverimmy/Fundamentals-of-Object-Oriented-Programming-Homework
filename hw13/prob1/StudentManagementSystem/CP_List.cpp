#include "CP_List.h"

CP_List::CP_List(): head(nullptr), tail(nullptr) {}

CP_Student* CP_List::front() {
    return head;
}

void CP_List::push_back(CP_Student* student) {
    if (!head) {
        head = tail = student;
    } else {
        tail->next = student;
        student->prev = tail;
        tail = student;
    }
}

void CP_List::pop_front() {
    if (!head) {
        return;
    }
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
}

void CP_List::pop_back() {
    if (!tail) {
        return;
    }
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
}

bool CP_List::empty() {
    return nullptr == head;
}
