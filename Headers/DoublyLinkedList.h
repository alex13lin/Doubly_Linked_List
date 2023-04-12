#ifndef DOUBLELINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class DoublyLinkedList {
private:

    typedef struct student {
        char name[20];
        int score;
        struct student *left_link;
        struct student *right_link;
    } Node_type;

    Node_type *ptr, *ptr_prev, *head, *prev, *current, *next;

    bool has_records();

    bool is_student_in_record(char *);

public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void insert_student();

    void delete_student();

    void modify_student();

    void display_students();

    void reverse_students();

    void sort_students_by_score();

};


#endif //DOUBLELINKEDLIST_DOUBLYLINKEDLIST_H
